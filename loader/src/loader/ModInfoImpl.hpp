#pragma once

#include "ModMetadataImpl.hpp"

#include <Geode/loader/Loader.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/utils/JsonValidation.hpp>
#include <Geode/utils/VersionInfo.hpp>

#pragma warning(disable : 4996) // deprecation

using namespace geode::prelude;

namespace geode {
    class [[deprecated]] ModInfo::Impl {
    public:
        ModMetadata::Impl m_metadata;
        std::optional<IssuesInfo> m_issues;
        std::vector<Dependency> m_dependencies;
        bool m_supportsDisabling = true;
        bool m_supportsUnloading = false;

        static Result<ModInfo> createFromGeodeZip(utils::file::Unzip& zip);
        static Result<ModInfo> createFromGeodeFile(ghc::filesystem::path const& path);
        static Result<ModInfo> createFromFile(ghc::filesystem::path const& path);
        static Result<ModInfo> create(ModJson const& json);

        ModJson toJSON() const;
        ModJson getRawJSON() const;

        bool operator==(ModInfo::Impl const& other) const;

        static bool validateID(std::string const& id);

        static Result<ModInfo> createFromSchemaV010(ModJson const& json);

        Result<> addSpecialFiles(ghc::filesystem::path const& dir);
        Result<> addSpecialFiles(utils::file::Unzip& zip);

        std::vector<std::pair<std::string, std::optional<std::string>*>> getSpecialFiles();
    };

    class [[deprecated]] ModInfoImpl {
    public:
        static ModInfo::Impl& getImpl(ModInfo& info);
    };
}
