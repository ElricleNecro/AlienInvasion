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
