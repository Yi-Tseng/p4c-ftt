#include <fstream>
#include <iostream>

#include "ir/ir.h"

#include "frontends/common/options.h"
#include "frontends/common/parseInput.h"
#include "frontends/p4/frontend.h"

#include "lib/nullstream.h"

#include "ftt_midend/ftt_midend.h"

class FTTOptions : public CompilerOptions {
 public:
    cstring outputFile = nullptr;
    FTTOptions() {
      registerOption("-o", "outfile",
              [this](const char* arg) { this->outputFile = arg; return true; },
              "Write output to outfile");
     }
};

using FTTContext = P4CContextWithOptions<FTTOptions>;

int main(int argc, char *const argv[]) {
    AutoCompileContext autoFTTContext(new FTTContext);
    auto& options = FTTContext::get().options();
    options.langVersion = CompilerOptions::FrontendVersion::P4_16;
    options.compilerVersion = "0.0.1";

    if (options.process(argc, argv) != nullptr)
        options.setInputFile();
    if (::errorCount() > 0)
        return 1;

    auto program = P4::parseP4File(options);

    if (program == nullptr || ::errorCount() > 0) {
        std::cerr << "Can't parse P4 file " << options.file << std::endl;
        return 1;
    }

    try {
        P4::FrontEnd fe;
        program = fe.run(options, program);
    } catch (const Util::P4CExceptionBase &bug) {
        std::cerr << bug.what() << std::endl;
        return 1;
    }

    if (program == nullptr || ::errorCount() > 0) {
        std::cerr << "Can't process P4 file " << options.file << " by frontend"<< std::endl;
        return 1;
    }

    FttMidEnd midEnd(options);

    const IR::ToplevelBlock *top = nullptr;
    try {
        top = midEnd.process(program);
    } catch (const Util::P4CExceptionBase &bug) {
        std::cerr << bug.what() << std::endl;
        return 1;
    }

    std::cout << top << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << program << std::endl;

    if (options.dumpJsonFile) {
        JSONGenerator(*openFile(options.dumpJsonFile, true), true) << top << std::endl;
    }



}
