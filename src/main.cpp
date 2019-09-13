#include "ofMain.h"
#include "ofxUnitTests.h"
#include "ofApp.h"

void printInputError(int argc, char **argv)
{
	std::string input;
	for (auto i = 1; i < argc - 1; i++)
	{
		input += argv[i];
		input += "";
	}
	ofLogError("ofPackageManager") << "unkown command:" << input;
}

int main(int argc, char **argv)
{
#if defined(TARGET_OSX) || defined(TARGET_LINUX)
	std::shared_ptr<ofColorsLoggerChannel> logger{
		new ofColorsLoggerChannel};
	ofSetLoggerChannel(logger);
#endif
	//    ofSetLogLevel(OF_LOG_VERBOSE);
	filesystem::path cwdPath = filesystem::current_path();

	ofPackageManager app(cwdPath.string());

	std::string task;
	if (argc > 1)
	{
		task = argv[1];
	}

	if (task == "add")
	{
		if (argc == 3)
		{
			app.addPackageToAddonsMakeFile(argv[2]);
		}
		else if (argc == 4)
		{
			string option = argv[2];
			if (option == "-A" || option == "--all")
			{
				app.addPackagesToAddonsMakeFile(argv[3]);
			}
		}
		else
		{
			ofLogError("ofPackageManager") << "invalid syntax";
		}
	}
	else if (task == "config")
	{
		if (argc == 2)
		{
			app.configurePackageManager();
		}
		if (argc == 3)
		{
			std::string option = argv[2];
			if (option == "-g" || option == "--global")
			{
				app.configurePackageManager(true);
			}
		}
	}
	else if (task == "doctor")
	{
		app.doctor();
	}
	else if (task == "generate")
	{
		std::string subtask = "project";

		if (argc == 3)
		{
			subtask = argv[2];
		}
		else if (argc > 3)
		{
			printInputError(argc, argv);
			app.printManual();
			return -1;
		}

		if (subtask == "project")
		{
			app.generateProject();
		}
		else if (subtask == "readme")
		{
			app.generateReadme();
		}
		else if (subtask == "database")
		{
			app.generateDatabaseEntryFile();
		}
		else
		{
			printInputError(argc, argv);
			app.printManual();
			return -1;
		}
	}
	else if (task == "help")
	{
		app.printManual();
	}
	else if (task == "info")
	{
		app.printInfo();
	}
	else if (task == "install")
	{
		if (argc == 2)
		{
			app.installPackagesFromAddonsMakeFile();
		}
		else if (argc >= 3)
		{
			std::string package;
			std::string destinationPath = "local_addons";
			bool global = false;
			if (argc == 3)
			{
				package = argv[2];
			}
			else if (argc == 4)
			{
				std::string option = argv[2];
				if (option == "-g" || option == "--global")
				{
					destinationPath = ofFilePath::join(app.getOfPath(), "addons");
					global = true;
				}
				package = argv[3];
			}
			else
			{
				printInputError(argc, argv);
				app.printManual();
				return -1;
			}

			auto installedPackage = app.installPackage(package, destinationPath);
			// TODO: move to app
			if (!global && !installedPackage._path.empty())
			{
				app.addPackageToAddonsMakeFile(installedPackage);
			}
		}
	}
	else if (task == "print")
	{
		std::string subtask = "packages";
		if (argc == 3)
		{
			subtask = argv[2];
		}
		if (subtask == "packages")
		{
			app.printAvailablePackages();
		}
		else if (subtask == "manual" || subtask == "man" || subtask == "help")
		{
			app.printManual();
		}
		else if (subtask == "version")
		{
			app.printVersion();
		}
		else
		{
			printInputError(argc, argv);
			app.printManual();
			return -1;
		}
	}
	else if (task == "search")
	{
		if (argc == 3)
		{
			app.searchPackageInDatabaseById(argv[2]);
		}
		else if (argc == 4)
		{
			std::string subtask = argv[2];
			if (subtask == "github")
			{
				app.searchPackageOnGithubByName(argv[3]);
			}
		}
		else if (argc == 5)
		{
			std::string subtask = argv[2];
			if (subtask == "github")
			{
				string option = argv[3];
				if (option == "-u" || option == "--user")
				{
					app.searchPackageOnGithubByUser(argv[4]);
				}
			}
		}
		else
		{
			printInputError(argc, argv);
			app.printManual();
			return -1;
		}
	}
	else if (task == "update")
	{
		app.updatePackagesDatabase();
	}
	else
	{
		ofLogError("ofPackageManager") << "unkown task" << task;
		app.printInfo();
		app.printManual();
	}

	ofLogNotice() << "Thanks for using ofPackageManager. If you find a bug then please report it on the github issue tracker (https://github.com/thomasgeissl/ofPackageManager/issues). See you soon.";
	return 0;
}