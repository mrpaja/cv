//
// Created by paja on 6/22/22.
//
#include "Importer.h"
#include <regex>
#include "File.h"
#include "Model.h"
#include "IRenderable.h"
#include "ObjFileParser.h"

bool IsFileFormatSupport(const std::string& fileEnding) {
    std::smatch m;
    std::regex rePattern("(O|o)(B|b)(J|j)");
    std::regex_search(fileEnding, m, rePattern);
    if (!m.empty()) {
        return true;
    } else {
        return false;
    }
}

std::unique_ptr<IRenderable> Importer::ImportModel(const std::string& pathToMesh) {
    auto meshFile = File(pathToMesh, File::FileType::Model);
    if (!IsFileFormatSupport(meshFile.GetFileEnding())) {
        return nullptr;
    }
    std::unique_ptr<Model> spRenderable = std::make_unique<Model>(ObjFileParser::GetMesh(meshFile), meshFile.GetFileName());
    spRenderable->SetTexture(ObjFileParser::GetTexture(meshFile));
    return spRenderable;
}
