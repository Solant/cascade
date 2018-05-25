import qbs

Project {
    CppApplication {
        Depends { name: "Qt.testlib" }
        consoleApplication: true
        files: [
            "tst_testtest.cpp",
            "plaingadget.h",
        ]
    }
}
