export module engine.core.config;

import std;

import engine.types;

namespace engine {

    export class Config {
    public:
        static Config from_file(const std::filesystem::path& path) {

            return Config{};
        }
    };

} // namespace engine