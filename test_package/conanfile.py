from conans import ConanFile, CMake
import os

class TestKvasirMpl(ConanFile):
	generators = "cmake"

	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()

	def test(self):
		os.chdir("bin")
		self.run(".%sexample" % os.sep)
