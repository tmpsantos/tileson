//
// Created by robin on 03.08.2019.
//

#ifndef TILESON_WANGSET_H
#define TILESON_WANGSET_H

#include <json.hpp>
#include "WangColor.h"
#include "WangTile.h"
#include "../objects/PropertyCollection.h"

namespace tson
{
    class WangSet
    {
        public:
            WangSet() = default;
            explicit WangSet(const nlohmann::json &json);
            bool parse(const nlohmann::json &json);

            [[nodiscard]] const std::string &getName() const;
            [[nodiscard]] int getTile() const;

            [[nodiscard]] const std::vector<tson::WangTile> &getWangTiles() const;
            [[nodiscard]] const std::vector<tson::WangColor> &getCornerColors() const;
            [[nodiscard]] const std::vector<tson::WangColor> &getEdgeColors() const;

            PropertyCollection &getProperties();

        private:
            std::string                  m_name;          /*! 'name': Name of the Wang set */
            int                          m_tile{};        /*! 'tile': Local ID of tile representing the Wang set */
            std::vector<tson::WangTile>  m_wangTiles;     /*! 'wangtiles': Array of Wang tiles */
            std::vector<tson::WangColor> m_cornerColors;  /*! 'cornercolors': Array of Wang colors */
            std::vector<tson::WangColor> m_edgeColors;    /*! 'edgecolors': Array of Wang colors */
            tson::PropertyCollection     m_properties; 	  /*! 'properties': A list of properties (name, value, type). */

    };
}

#endif //TILESON_WANGSET_H
