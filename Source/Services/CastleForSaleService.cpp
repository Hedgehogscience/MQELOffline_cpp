/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides implementations for Castle-market services.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void GetCastlesForSale(Gameserver *Server, std::string Request, std::string Body)
{
    /*
        TODO(Convery):
        Remove the hardcoded response.
    */

    nlohmann::json Response = R"({"Result":{"CastlesForSale":[{"SaleId":1,"CastleInfoSummary":{"DefenderAccountSummary":{"Id":1000,"DisplayName":"Theme A","AvatarId":10,"CastleLevel":1},"CastleType":1,"Level":1,"IsNew":true,"IsCastleAttackable":true,"LastPublishedDate":"2014-07-03T17:34:20Z","CastleThemeId":21,"CastleHeartRank":1},"CastleTitleOasisID":15328,"CastleDescriptionOasisID":15332,"FakePriceOasisID":15336,"CastleIconUrl":"UI_Common_CastleSelection_Preview:A","CanBePurchased":true,"SpawnPlotId":1},{"SaleId":2,"CastleInfoSummary":{"DefenderAccountSummary":{"Id":1001,"DisplayName":"Theme B","AvatarId":10,"CastleLevel":1},"CastleType":1,"Level":1,"IsNew":true,"IsCastleAttackable":true,"LastPublishedDate":"2014-07-03T17:34:20Z","CastleThemeId":22,"CastleHeartRank":1},"CastleTitleOasisID":15329,"CastleDescriptionOasisID":15333,"FakePriceOasisID":15336,"CastleIconUrl":"UI_Common_CastleSelection_Preview:B","CanBePurchased":true,"SpawnPlotId":2},{"SaleId":3,"CastleInfoSummary":{"DefenderAccountSummary":{"Id":1002,"DisplayName":"Theme C","AvatarId":10,"CastleLevel":1},"CastleType":1,"Level":1,"IsNew":true,"IsCastleAttackable":true,"LastPublishedDate":"2014-07-03T17:34:20Z","CastleThemeId":23,"CastleHeartRank":1},"CastleTitleOasisID":15330,"CastleDescriptionOasisID":15334,"FakePriceOasisID":15336,"CastleIconUrl":"UI_Common_CastleSelection_Preview:C","CanBePurchased":true,"SpawnPlotId":3},{"SaleId":4,"CastleInfoSummary":{"DefenderAccountSummary":{"Id":1003,"DisplayName":"Pink Castle","AvatarId":10,"CastleLevel":1},"CastleType":1,"Level":1,"IsNew":true,"IsCastleAttackable":true,"LastPublishedDate":"2014-07-03T17:34:20Z","CastleThemeId":9,"CastleHeartRank":1},"CastleTitleOasisID":15331,"CastleDescriptionOasisID":15335,"FakePriceOasisID":15337,"CastleIconUrl":"UI_Common_CastleSelection_Preview:Firesly","CastleModelIndex":1,"IsInteractive":true}]}})"_json;

    // Patch the base response with our data.

    Sendreply(Server, Response.dump(4));
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/CastleForSaleService.hqs/GetCastlesForSale", GetCastlesForSale);
        };
    };
    static Startup Loader{};
}
