from conans import ConanFile, CMake, tools
import re

def get_project_version():
    try:
        content = tools.load("src/CMakeLists.txt")
        version = re.search(r"project\([^\)]+VERSION (\d+\.\d+\.\d+)[^\)]*\)", content).group(1)
        return version.strip()
    except Exception:
        return None

		
def get_project_name():
    try:
        content = tools.load("src/CMakeLists.txt")
        name = re.search(r"project\(([^\) ]+)[^\)]*\)", content).group(1)
        return name.strip()
    except Exception:
        return None

		
class Project(ConanFile):
    name = get_project_name()
    version = get_project_version()
    author = "A"
    license = ""
    url = ""
    description = "better_containers"
    exports = ["LICENSE.md"]
    settings = "os", "compiler", "build_type", "arch"
    requires = []
    default_options = {
        "gtest:shared": False
    }
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto",
        "submodule": "recursive"
    }
    generators = "cmake"

    @property
    def _run_tests(self):
        return tools.get_env("CONAN_RUN_TESTS", False)

    def _configure_cmake(self, folder="src"):
        cmake = CMake(self, generator="Ninja")
        cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = True

        if self.settings.compiler == "Visual Studio" and self.options.shared:
            cmake.definitions["CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS"] = True
        if self._run_tests:
            # developer's mode (unit tests, examples, restrictive compilation warnings, ...)
            cmake.configure()
        else:
            # consumer's mode (library sources only)
            cmake.configure(source_folder=folder, build_folder=folder)
        return cmake

    def build_requirements(self):
        if self._run_tests:
            self.build_requires("gtest/1.10.0")

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        if self._run_tests:
            self.run("ctest -VV -C %s" % cmake.build_type, run_environment=True)

    def package(self):
        self.copy(
			pattern="*license*",
			dst="licenses",
			excludes="tools/cmake-scripts/*",
			ignore_case=True,
			keep_path=False
		)
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ['better_containers']

    def package_id(self):
        self.info.header_only()
