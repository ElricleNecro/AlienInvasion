newoption(
	{
		trigger="install-prefix",
		value="DIR",
		description="Directory used to install bin, lib and share directory.",
	}
)

newoption(
	{
		trigger="type",
		value="TYPE",
		description="Working type for stars coordinates.",
	}
)

if not _OPTIONS["type"] then
	_OPTIONS["type"] = "double"
end

if not _OPTIONS["install-prefix"] then
	_OPTIONS["install-prefix"] = os.getenv("HOME") .. "/.local/"
end

print(_OPTIONS)

io.input("config.h.cmake")
local text = io.read("*a")

text = string.gsub(text, "@F_TYPE@", _OPTIONS["type"])
text = string.gsub(text, "@CMAKE_INSTALL_PREFIX@", _OPTIONS["install-prefix"])

text = string.gsub(text, "@PLUGIN_API_VERSION_MAJOR@", "0")
text = string.gsub(text, "@PLUGIN_API_VERSION_MINOR@", "1")

text = string.gsub(text, "@AI_VERSION_MAJOR@", "0")
text = string.gsub(text, "@AI_VERSION_MINOR@", "1")

io.output("include/config.hpp")
io.write(text)
io.close()

solution("AlienInvasion")
	configurations({"debug", "release"})
		buildoptions(
			{
				"-std=c++11",
				"-I include/"
			}
		)

		flags(
			{
				"ExtraWarnings"
			}
		)

	configuration("debug")
		buildoptions(
			{
				"-g"
			}
		)

	includedirs(
		{
			"include/"
		}
	)

	project("AlienInvasion")
		language("C++")
		kind("ConsoleApp")

		location("build/bin")
		targetdir("build/bin")

		files(
			{
				"src/main.cpp"
			}
		)

		links(
			{
				"profile_gen"
			}
		)
		libdirs(
			{
				"build/lib"
			}
		)

	project("profile_gen")
		language("C++")
		kind("SharedLib")

		location("build/lib")
		targetdir("build/lib")

		files(
			{
				"src/profile/*.cpp"
			}
		)
	project("tree")
		language("C++")
		kind("SharedLib")

		location("build/lib")
		targetdir("build/lib")

		files(
			{
				"src/tree/*.cpp"
			}
		)
