import qbs

Project {
    CppApplication {
        Depends { name: "Qt.testlib" }
	Depends { name: "cascade" }
        consoleApplication: true
        files: [
            "tst_testtest.cpp",
            "plaingadget.h",
        ]
    }
    references: ["../cascade.qbs"]
}
