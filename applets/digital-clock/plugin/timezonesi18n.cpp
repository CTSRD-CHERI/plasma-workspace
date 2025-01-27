/*
    SPDX-FileCopyrightText: 2014 Martin Klapetek <mklapetek@kde.org>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#include "timezonesi18n.h"

#include <KLocalizedString>

#include "timezonesi18n_generated.h"

TimezonesI18n::TimezonesI18n(QObject *parent)
    : QObject(parent)
    , m_isInitialized(false)
{
}

QString TimezonesI18n::i18nCity(const QString &city)
{
    if (!m_isInitialized) {
        init();
    }
    return m_i18nCities.value(city, city);
}

QString TimezonesI18n::i18nContinents(const QString &continent)
{
    if (!m_isInitialized) {
        init();
    }
    return m_i18nContinents.value(continent, continent);
}

QString TimezonesI18n::i18nCountry(QLocale::Country country)
{
    if (!m_isInitialized) {
        init();
    }

    QString countryName = m_i18nCountries.value(country);

    if (countryName.isEmpty()) {
        countryName = QLocale::countryToString(country);
        m_i18nCountries.insert(country, countryName);
    }

    return countryName;
}

void TimezonesI18n::init()
{
    m_i18nCities = TimezonesI18nData::timezoneCityToL10nMap();
    m_i18nContinents = TimezonesI18nData::timezoneContinentToL10nMap();

#define ENTRY_ISO_3166(qlocale_enum, string) {QLocale::qlocale_enum, i18nd("iso_3166", string)}
    /* Make sure the country names match their versions in iso-codes,
     * ISO 3166. */
    m_i18nCountries = QHash<QLocale::Country, QString>({
        ENTRY_ISO_3166(IvoryCoast, "Côte d'Ivoire"),
        ENTRY_ISO_3166(Ghana, "Ghana"),
        ENTRY_ISO_3166(Ethiopia, "Ethiopia"),
        ENTRY_ISO_3166(Algeria, "Algeria"),
        ENTRY_ISO_3166(Eritrea, "Eritrea"),
        ENTRY_ISO_3166(Mali, "Mali"),
        ENTRY_ISO_3166(CentralAfricanRepublic, "Central African Republic"),
        ENTRY_ISO_3166(Gambia, "Gambia"),
        ENTRY_ISO_3166(GuineaBissau, "Guinea-Bissau"),
        ENTRY_ISO_3166(Malawi, "Malawi"),
        ENTRY_ISO_3166(CongoBrazzaville, "Congo"),
        ENTRY_ISO_3166(Burundi, "Burundi"),
        ENTRY_ISO_3166(Egypt, "Egypt"),
        ENTRY_ISO_3166(Morocco, "Morocco"),
        ENTRY_ISO_3166(Spain, "Spain"),
        ENTRY_ISO_3166(Guinea, "Guinea"),
        ENTRY_ISO_3166(Senegal, "Senegal"),
        ENTRY_ISO_3166(Tanzania, "Tanzania"),
        ENTRY_ISO_3166(Djibouti, "Djibouti"),
        ENTRY_ISO_3166(Cameroon, "Cameroon"),
        ENTRY_ISO_3166(WesternSahara, "Western Sahara"),
        ENTRY_ISO_3166(SierraLeone, "Sierra Leone"),
        ENTRY_ISO_3166(Botswana, "Botswana"),
        ENTRY_ISO_3166(BouvetIsland, "Bouvet Island"),
        ENTRY_ISO_3166(Zimbabwe, "Zimbabwe"),
        ENTRY_ISO_3166(SouthAfrica, "South Africa"),
        ENTRY_ISO_3166(SouthSudan, "South Sudan"),
        ENTRY_ISO_3166(Uganda, "Uganda"),
        ENTRY_ISO_3166(Sudan, "Sudan"),
        ENTRY_ISO_3166(Rwanda, "Rwanda"),
        ENTRY_ISO_3166(CongoKinshasa, "Congo, The Democratic Republic of the"),
        ENTRY_ISO_3166(Nigeria, "Nigeria"),
        ENTRY_ISO_3166(Gabon, "Gabon"),
        ENTRY_ISO_3166(Togo, "Togo"),
        ENTRY_ISO_3166(Angola, "Angola"),
        ENTRY_ISO_3166(Zambia, "Zambia"),
        ENTRY_ISO_3166(EquatorialGuinea, "Equatorial Guinea"),
        ENTRY_ISO_3166(Mozambique, "Mozambique"),
        ENTRY_ISO_3166(Lesotho, "Lesotho"),
        ENTRY_ISO_3166(Swaziland, "Swaziland"),
        ENTRY_ISO_3166(Somalia, "Somalia"),
        ENTRY_ISO_3166(Liberia, "Liberia"),
        ENTRY_ISO_3166(Kenya, "Kenya"),
        ENTRY_ISO_3166(Chad, "Chad"),
        ENTRY_ISO_3166(Niger, "Niger"),
        ENTRY_ISO_3166(Mauritania, "Mauritania"),
        ENTRY_ISO_3166(BurkinaFaso, "Burkina Faso"),
        ENTRY_ISO_3166(Benin, "Benin"),
        ENTRY_ISO_3166(SaoTomeAndPrincipe, "Sao Tome and Principe"),
        ENTRY_ISO_3166(Libya, "Libya"),
        ENTRY_ISO_3166(Tunisia, "Tunisia"),
        ENTRY_ISO_3166(Namibia, "Namibia"),
        ENTRY_ISO_3166(UnitedStates, "United States"),
        ENTRY_ISO_3166(Anguilla, "Anguilla"),
        ENTRY_ISO_3166(AntiguaAndBarbuda, "Antigua and Barbuda"),
        ENTRY_ISO_3166(Brazil, "Brazil"),
        ENTRY_ISO_3166(Argentina, "Argentina"),
        ENTRY_ISO_3166(Aruba, "Aruba"),
        ENTRY_ISO_3166(Paraguay, "Paraguay"),
        ENTRY_ISO_3166(Canada, "Canada"),
        ENTRY_ISO_3166(Mexico, "Mexico"),
        ENTRY_ISO_3166(Barbados, "Barbados"),
        ENTRY_ISO_3166(Belize, "Belize"),
        ENTRY_ISO_3166(Colombia, "Colombia"),
        ENTRY_ISO_3166(Venezuela, "Venezuela"),
        ENTRY_ISO_3166(FrenchGuiana, "French Guiana"),
        ENTRY_ISO_3166(CaymanIslands, "Cayman Islands"),
        ENTRY_ISO_3166(CostaRica, "Costa Rica"),
        ENTRY_ISO_3166(CuraSao, "Curaçao"),
        ENTRY_ISO_3166(Greenland, "Greenland"),
        ENTRY_ISO_3166(Dominica, "Dominica"),
        ENTRY_ISO_3166(ElSalvador, "El Salvador"),
        ENTRY_ISO_3166(TurksAndCaicosIslands, "Turks and Caicos Islands"),
        ENTRY_ISO_3166(Grenada, "Grenada"),
        ENTRY_ISO_3166(Guadeloupe, "Guadeloupe"),
        ENTRY_ISO_3166(Guatemala, "Guatemala"),
        ENTRY_ISO_3166(Ecuador, "Ecuador"),
        ENTRY_ISO_3166(Guyana, "Guyana"),
        ENTRY_ISO_3166(Cuba, "Cuba"),
        ENTRY_ISO_3166(Jamaica, "Jamaica"),
        ENTRY_ISO_3166(Bonaire, "Bonaire, Sint Eustatius and Saba"),
        ENTRY_ISO_3166(Bolivia, "Bolivia"),
        ENTRY_ISO_3166(Peru, "Peru"),
        ENTRY_ISO_3166(SintMaarten, "Sint Maarten (Dutch part)"),
        ENTRY_ISO_3166(Nicaragua, "Nicaragua"),
        ENTRY_ISO_3166(SaintMartin, "Saint Martin (French part)"),
        ENTRY_ISO_3166(Martinique, "Martinique"),
        ENTRY_ISO_3166(SaintPierreAndMiquelon, "Saint Pierre and Miquelon"),
        ENTRY_ISO_3166(Uruguay, "Uruguay"),
        ENTRY_ISO_3166(Montserrat, "Montserrat"),
        ENTRY_ISO_3166(Bahamas, "Bahamas"),
        ENTRY_ISO_3166(Panama, "Panama"),
        ENTRY_ISO_3166(Suriname, "Suriname"),
        ENTRY_ISO_3166(Haiti, "Haiti"),
        ENTRY_ISO_3166(HeardAndMcDonaldIslands, "Heard Island and McDonald Islands"),
        ENTRY_ISO_3166(TrinidadAndTobago, "Trinidad and Tobago"),
        ENTRY_ISO_3166(PuertoRico, "Puerto Rico"),
        ENTRY_ISO_3166(Chile, "Chile"),
        ENTRY_ISO_3166(DominicanRepublic, "Dominican Republic"),
        ENTRY_ISO_3166(SaintBarthelemy, "Saint Barthélemy"),
        ENTRY_ISO_3166(SaintKittsAndNevis, "Saint Kitts and Nevis"),
        ENTRY_ISO_3166(SaintLucia, "Saint Lucia"),
        ENTRY_ISO_3166(UnitedStatesVirginIslands, "Virgin Islands, U.S."),
        ENTRY_ISO_3166(SaintVincentAndTheGrenadines, "Saint Vincent and the Grenadines"),
        ENTRY_ISO_3166(Honduras, "Honduras"),
        ENTRY_ISO_3166(BritishVirginIslands, "Virgin Islands, British"),
        ENTRY_ISO_3166(Antarctica, "Antarctica"),
        ENTRY_ISO_3166(Australia, "Australia"),
        ENTRY_ISO_3166(SvalbardAndJanMayenIslands, "Svalbard and Jan Mayen"),
        ENTRY_ISO_3166(Yemen, "Yemen"),
        ENTRY_ISO_3166(Kazakhstan, "Kazakhstan"),
        ENTRY_ISO_3166(Jordan, "Jordan"),
        ENTRY_ISO_3166(Russia, "Russian Federation"),
        ENTRY_ISO_3166(Turkmenistan, "Turkmenistan"),
        ENTRY_ISO_3166(Iraq, "Iraq"),
        ENTRY_ISO_3166(Bahrain, "Bahrain"),
        ENTRY_ISO_3166(Azerbaijan, "Azerbaijan"),
        ENTRY_ISO_3166(Thailand, "Thailand"),
        ENTRY_ISO_3166(Lebanon, "Lebanon"),
        ENTRY_ISO_3166(Kyrgyzstan, "Kyrgyzstan"),
        ENTRY_ISO_3166(Brunei, "Brunei Darussalam"),
        ENTRY_ISO_3166(Mongolia, "Mongolia"),
        ENTRY_ISO_3166(China, "China"),
        ENTRY_ISO_3166(SriLanka, "Sri Lanka"),
        ENTRY_ISO_3166(Syria, "Syrian Arab Republic"),
        ENTRY_ISO_3166(Bangladesh, "Bangladesh"),
        ENTRY_ISO_3166(EastTimor, "Timor-Leste"),
        ENTRY_ISO_3166(UnitedArabEmirates, "United Arab Emirates"),
        ENTRY_ISO_3166(Tajikistan, "Tajikistan"),
        ENTRY_ISO_3166(PalestinianTerritories, "Palestine, State of"),
        ENTRY_ISO_3166(Vietnam, "Vietnam"),
        ENTRY_ISO_3166(HongKong, "Hong Kong"),
        ENTRY_ISO_3166(Indonesia, "Indonesia"),
        ENTRY_ISO_3166(Israel, "Israel"),
        ENTRY_ISO_3166(Afghanistan, "Afghanistan"),
        ENTRY_ISO_3166(Pakistan, "Pakistan"),
        ENTRY_ISO_3166(Nepal, "Nepal"),
        ENTRY_ISO_3166(India, "India"),
        ENTRY_ISO_3166(Malaysia, "Malaysia"),
        ENTRY_ISO_3166(Kuwait, "Kuwait"),
        ENTRY_ISO_3166(Macau, "Macao"),
        ENTRY_ISO_3166(Philippines, "Philippines"),
        ENTRY_ISO_3166(Oman, "Oman"),
        ENTRY_ISO_3166(Cyprus, "Cyprus"),
        ENTRY_ISO_3166(Cambodia, "Cambodia"),
        ENTRY_ISO_3166(NorthKorea, "Korea, Democratic People's Republic of"),
        ENTRY_ISO_3166(Qatar, "Qatar"),
        ENTRY_ISO_3166(Myanmar, "Myanmar"),
        ENTRY_ISO_3166(SaudiArabia, "Saudi Arabia"),
        ENTRY_ISO_3166(Uzbekistan, "Uzbekistan"),
        ENTRY_ISO_3166(SouthKorea, "Korea, Republic of"),
        ENTRY_ISO_3166(Singapore, "Singapore"),
        ENTRY_ISO_3166(Taiwan, "Taiwan"),
        ENTRY_ISO_3166(Georgia, "Georgia"),
        ENTRY_ISO_3166(Iran, "Iran, Islamic Republic of"),
        ENTRY_ISO_3166(Bhutan, "Bhutan"),
        ENTRY_ISO_3166(Japan, "Japan"),
        ENTRY_ISO_3166(Laos, "Lao People's Democratic Republic"),
        ENTRY_ISO_3166(Armenia, "Armenia"),
        ENTRY_ISO_3166(Portugal, "Portugal"),
        ENTRY_ISO_3166(Bermuda, "Bermuda"),
        ENTRY_ISO_3166(CapeVerde, "Cabo Verde"),
        ENTRY_ISO_3166(FaroeIslands, "Faroe Islands"),
        ENTRY_ISO_3166(Iceland, "Iceland"),
        ENTRY_ISO_3166(SouthGeorgiaAndTheSouthSandwichIslands, "South Georgia and the South Sandwich Islands"),
        ENTRY_ISO_3166(SaintHelena, "Saint Helena, Ascension and Tristan da Cunha"),
        ENTRY_ISO_3166(FalklandIslands, "Falkland Islands (Malvinas)"),
        ENTRY_ISO_3166(Netherlands, "Netherlands"),
        ENTRY_ISO_3166(Andorra, "Andorra"),
        ENTRY_ISO_3166(Greece, "Greece"),
        ENTRY_ISO_3166(Serbia, "Serbia"),
        ENTRY_ISO_3166(Germany, "Germany"),
        ENTRY_ISO_3166(Slovakia, "Slovakia"),
        ENTRY_ISO_3166(Belgium, "Belgium"),
        ENTRY_ISO_3166(Romania, "Romania"),
        ENTRY_ISO_3166(Hungary, "Hungary"),
        ENTRY_ISO_3166(Moldova, "Moldova"),
        ENTRY_ISO_3166(Denmark, "Denmark"),
        ENTRY_ISO_3166(Ireland, "Ireland"),
        ENTRY_ISO_3166(Gibraltar, "Gibraltar"),
        ENTRY_ISO_3166(Guernsey, "Guernsey"),
        ENTRY_ISO_3166(Finland, "Finland"),
        ENTRY_ISO_3166(IsleOfMan, "Isle of Man"),
        ENTRY_ISO_3166(Turkey, "Turkey"),
        ENTRY_ISO_3166(Jersey, "Jersey"),
        ENTRY_ISO_3166(Ukraine, "Ukraine"),
        ENTRY_ISO_3166(Slovenia, "Slovenia"),
        ENTRY_ISO_3166(UnitedKingdom, "United Kingdom"),
        ENTRY_ISO_3166(Luxembourg, "Luxembourg"),
        ENTRY_ISO_3166(Malta, "Malta"),
        ENTRY_ISO_3166(AlandIslands, "Åland Islands"),
        ENTRY_ISO_3166(Belarus, "Belarus"),
        ENTRY_ISO_3166(Monaco, "Monaco"),
        ENTRY_ISO_3166(Norway, "Norway"),
        ENTRY_ISO_3166(France, "France"),
        ENTRY_ISO_3166(Montenegro, "Montenegro"),
        ENTRY_ISO_3166(CzechRepublic, "Czechia"),
        ENTRY_ISO_3166(Latvia, "Latvia"),
        ENTRY_ISO_3166(Italy, "Italy"),
        ENTRY_ISO_3166(SanMarino, "San Marino"),
        ENTRY_ISO_3166(BosniaAndHerzegowina, "Bosnia and Herzegovina"),
        ENTRY_ISO_3166(Macedonia, "Macedonia, Republic of"),
        ENTRY_ISO_3166(Bulgaria, "Bulgaria"),
        ENTRY_ISO_3166(Sweden, "Sweden"),
        ENTRY_ISO_3166(Estonia, "Estonia"),
        ENTRY_ISO_3166(Albania, "Albania"),
        ENTRY_ISO_3166(Liechtenstein, "Liechtenstein"),
        ENTRY_ISO_3166(VaticanCityState, "Holy See (Vatican City State)"),
        ENTRY_ISO_3166(Austria, "Austria"),
        ENTRY_ISO_3166(Lithuania, "Lithuania"),
        ENTRY_ISO_3166(Poland, "Poland"),
        ENTRY_ISO_3166(Croatia, "Croatia"),
        ENTRY_ISO_3166(Switzerland, "Switzerland"),
        ENTRY_ISO_3166(Madagascar, "Madagascar"),
        ENTRY_ISO_3166(BritishIndianOceanTerritory, "British Indian Ocean Territory"),
        ENTRY_ISO_3166(ChristmasIsland, "Christmas Island"),
        ENTRY_ISO_3166(CocosIslands, "Cocos (Keeling) Islands"),
        ENTRY_ISO_3166(Comoros, "Comoros"),
        ENTRY_ISO_3166(FrenchSouthernTerritories, "French Southern Territories"),
        ENTRY_ISO_3166(Seychelles, "Seychelles"),
        ENTRY_ISO_3166(Maldives, "Maldives"),
        ENTRY_ISO_3166(Mauritius, "Mauritius"),
        ENTRY_ISO_3166(Mayotte, "Mayotte"),
        ENTRY_ISO_3166(Reunion, "Réunion"),
        ENTRY_ISO_3166(Samoa, "Samoa"),
        ENTRY_ISO_3166(NewZealand, "New Zealand"),
        ENTRY_ISO_3166(Micronesia, "Micronesia, Federated States of"),
        ENTRY_ISO_3166(Vanuatu, "Vanuatu"),
        ENTRY_ISO_3166(Kiribati, "Kiribati"),
        ENTRY_ISO_3166(TokelauCountry, "Tokelau"),
        ENTRY_ISO_3166(Fiji, "Fiji"),
        ENTRY_ISO_3166(TuvaluCountry, "Tuvalu"),
        ENTRY_ISO_3166(FrenchPolynesia, "French Polynesia"),
        ENTRY_ISO_3166(SolomonIslands, "Solomon Islands"),
        ENTRY_ISO_3166(Guam, "Guam"),
        ENTRY_ISO_3166(UnitedStatesMinorOutlyingIslands, "United States Minor Outlying Islands"),
        ENTRY_ISO_3166(MarshallIslands, "Marshall Islands"),
        ENTRY_ISO_3166(NauruCountry, "Nauru"),
        ENTRY_ISO_3166(Niue, "Niue"),
        ENTRY_ISO_3166(NorfolkIsland, "Norfolk Island"),
        ENTRY_ISO_3166(NewCaledonia, "New Caledonia"),
        ENTRY_ISO_3166(AmericanSamoa, "American Samoa"),
        ENTRY_ISO_3166(Palau, "Palau"),
        ENTRY_ISO_3166(Pitcairn, "Pitcairn"),
        ENTRY_ISO_3166(PapuaNewGuinea, "Papua New Guinea"),
        ENTRY_ISO_3166(CookIslands, "Cook Islands"),
        ENTRY_ISO_3166(NorthernMarianaIslands, "Northern Mariana Islands"),
        ENTRY_ISO_3166(Tonga, "Tonga"),
        ENTRY_ISO_3166(WallisAndFutunaIslands, "Wallis and Futuna")
        //           {QLocale::Default,                    i18nc("This is a country name associated with a particular time zone in a zone selection dialog",
        //           "Default")} },
    });
#undef ENTRY_ISO_3166

    m_isInitialized = true;
}
