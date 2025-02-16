#pragma once

#include "ofMain.h"
#include "ofxGit2.h"

#include "ofPackage.h"
#include "defines.h"
#include "version.h"

class ofPackageManager
{
public:
	ofPackageManager(std::string cwdPath);

	void addPackageToAddonsMakeFile(ofPackage package);
	void addPackageToAddonsMakeFile(std::string path);
	void addPackagesToAddonsMakeFile(std::string path);
	void addPackagesToAddonsMakeFile(std::vector<std::string> paths);
	void configure(bool global = false);
	void doctor();
	void generateDatabaseEntryFile();

	void installPackagesFromAddonsMakeFile();
	void installDependenciesFromAddonConfig(std::string path, std::string destination);

	ofPackage installPackage(std::string key, std::string destinationPath = "");
	ofPackage installPackageById(std::string id, std::string checkout = "", std::string destinationPath = "");
	ofPackage installPackageByGithub(std::string github, std::string checkout = "", std::string destinationPath = "");
	ofPackage installPackageByUrl(std::string url, std::string checkout = "", std::string destinationPath = "");
	ofPackage maybeInstallOneOfThePackages(ofJson packages, std::string destinationPath);

	void printInfo();
	void printPaths();
	void printManual();
	void printAvailablePackages();
	void printVersion();
	void searchPackageInDatabaseById(std::string id);
	ofJson searchPackageOnGithubByName(std::string name);
	ofJson searchPackageOnGithubByUser(std::string user);
	void updatePackagesDatabase();
	bool isCoreAddon(std::string id);

	std::string getOfPath();
	ofJson getConfig();
	std::string generateGithubUrl(std::string github);
	std::string getAbsolutePath(std::string path);
	std::pair<std::string, std::string> getPathAndName(std::string name);

	bool isGitRepository(std::string path);
	bool isGitUrl(std::string path);
	bool isGithubPair(std::string path);
	bool hasAddonsMakeFile(std::string path);
	bool hasAddonConfigFile(std::string path);

	std::string _cwdPath;
	ofJson _configJson;
};
