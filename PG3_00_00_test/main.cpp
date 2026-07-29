#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>

using StationList = std::list<const char*>;

StationList::iterator FindStation(StationList& stations, const char* stationName)
{
    for (auto station = stations.begin(); station != stations.end(); ++station)
    {
        if (std::strcmp(*station, stationName) == 0)
        {
            return station;
        }
    }

    return stations.end();
}

bool InsertStationBefore(
    StationList& stations,
    const char* nextStationName,
    const char* newStationName)
{
    const auto nextStation = FindStation(stations, nextStationName);
    if (nextStation == stations.end())
    {
        return false;
    }

    stations.insert(nextStation, newStationName);
    return true;
}

const char* NextStation(
    StationList::const_iterator& station,
    const StationList::const_iterator& end)
{
    if (station == end)
    {
        return "-";
    }

    const char* stationName = *station;
    ++station;
    return stationName;
}

void PrintStationLists(
    const StationList& stations1970,
    const StationList& stations2019,
    const StationList& stations2022)
{
    constexpr int kNumberWidth = 5;
    constexpr int kStationWidth = 21;

    std::cout << "Yamanote Line Station Lists\n\n";
    std::cout << std::left
              << std::setw(kNumberWidth) << "No."
              << std::setw(kStationWidth) << "1970 (28 stations)"
              << std::setw(kStationWidth) << "2019 (29 stations)"
              << "2022 (30 stations)\n";
    std::cout << "--------------------------------------------------------------------\n";

    auto station1970 = stations1970.cbegin();
    auto station2019 = stations2019.cbegin();
    auto station2022 = stations2022.cbegin();

    for (std::size_t number = 1; number <= stations2022.size(); ++number)
    {
        std::cout << std::right << std::setw(2) << number << ".  "
                  << std::left
                  << std::setw(kStationWidth)
                  << NextStation(station1970, stations1970.cend())
                  << std::setw(kStationWidth)
                  << NextStation(station2019, stations2019.cend())
                  << NextStation(station2022, stations2022.cend())
                  << '\n';
    }
}

int main()
{
    // The 1970 list has 28 stations. The two stations opened later are
    // inserted into copies of this list in their correct line positions.
    const StationList stations1970 =
    {
        "Tokyo",
        "Kanda",
        "Akihabara",
        "Okachimachi",
        "Ueno",
        "Uguisudani",
        "Nippori",
        "Tabata",
        "Komagome",
        "Sugamo",
        "Otsuka",
        "Ikebukuro",
        "Mejiro",
        "Takadanobaba",
        "Shin-Okubo",
        "Shinjuku",
        "Yoyogi",
        "Harajuku",
        "Shibuya",
        "Ebisu",
        "Meguro",
        "Gotanda",
        "Osaki",
        "Shinagawa",
        "Tamachi",
        "Hamamatsucho",
        "Shimbashi",
        "Yurakucho"
    };

    StationList stations2019 = stations1970;
    if (!InsertStationBefore(
            stations2019,
            "Tabata",
            "Nishi-Nippori"))
    {
        std::cerr << "Failed to insert Nishi-Nippori.\n";
        return 1;
    }

    StationList stations2022 = stations2019;
    if (!InsertStationBefore(
            stations2022,
            "Tamachi",
            "Takanawa Gateway"))
    {
        std::cerr << "Failed to insert Takanawa Gateway.\n";
        return 1;
    }

    PrintStationLists(stations1970, stations2019, stations2022);

    return 0;
}
