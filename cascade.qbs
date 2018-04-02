import qbs

DynamicLibrary {
    Depends {
        name: "Qt"
        submodules: ["core"]
    }
    cpp.cxxLanguageVersion: "c++11"
    bundle.isBundle: false
    cpp.visibility: "minimal"
    files: [
        "src/cascade.cpp",
        "src/cascade.h",
        "src/cascade_global.h",
    ]
    Export {
        Depends { name: "cpp" }
        cpp.includePaths: "src/"
    }

    Group {
        qbs.install: true
        qbs.installDir: {
            return "lib"
        }
        fileTagsFilter: "dynamiclibrary"
    }
}
