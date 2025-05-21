#pragma once

#include <iostream>
#include <string>

class ConfigurationManager {
  public:
    static ConfigurationManager& getInstance() {
      static ConfigurationManager instance;
      return instance;
    }

    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    void sayHello() {
      std::cout << "Hello from ConfigurationManager!" << std::endl;
    }
  private:
    ConfigurationManager() {
      std::cout << "ConfigurationManager initialized." << std::endl;
    }

    ~ConfigurationManager() {
      std::cout << "ConfigurationManager destroyed." << std::endl;
    }

    std::string configData = "Default Config Data";
};
