
#include <iostream>
#include <string>
#include <vector>

// Defining positions

enum Positions
{
    goalkeeper = 1,   
    forward = 2
};

class footballPlayer
{
public:
    std::string playerName{};
    int skillsLevel{};
    std::string team{};
    Positions position{};
    int matchesPlayed{};
    int goalsScored{};
};

class footballTeam
{
public:
    std::string teamName{};
    std::vector<footballPlayer> teamPlayers{};
    int points{};
};

class footballMatch
{
public:
    std::string teamA{};
    std::string teamB{};
    std::string matchWinner{};
};

struct referee
{
    std::string name{};
    int joinedMatches{};
};


int findKeeperSkill(const footballTeam& team)
{
    for (const footballPlayer& p : team.teamPlayers)
    {
        if (p.position == Positions::goalkeeper)
        {
            return p.skillsLevel;
        }
    }
    return 0;   // in case no keeper is found
}

// only forwards attack.
// A forward with skill >= 30 scores 2 goals regardless of the keeper;
// otherwise a forward scores 1 if his skill is strictly higher than
// the keeper's. 

int attack(footballTeam& attackers, int keeperSkill)
{
    int goals = 0;
    for (footballPlayer& p : attackers.teamPlayers)   
    {
        if (p.position == Positions::forward)
        {
            if (p.skillsLevel >= 30)
            {
                p.goalsScored += 2;
                goals += 2;
            }
            else if (p.skillsLevel > keeperSkill)
            {
                p.goalsScored += 1;
                goals += 1;
            }
        }
        ++p.matchesPlayed;   
    }
    return goals;
}

// Function which plays the match 

footballMatch playGame(footballTeam& teamA, footballTeam& teamB, referee& ref)
{
    int goalsA = attack(teamA, findKeeperSkill(teamB));
    int goalsB = attack(teamB, findKeeperSkill(teamA));

    footballMatch record;
    record.teamA = teamA.teamName;
    record.teamB = teamB.teamName;

    if (goalsA > goalsB)
    {
        teamA.points += 3;
        record.matchWinner = teamA.teamName;
    }
    else if (goalsB > goalsA)
    {
        teamB.points += 3;
        record.matchWinner = teamB.teamName;
    }
    else
    {
        teamA.points += 1;
        teamB.points += 1;
        record.matchWinner = "Draw";
    }

    ++ref.joinedMatches;
    return record;
}

void printStandings(const std::vector<footballTeam>& league)
{
    std::cout << "**** Standings ****\n";
    for (const footballTeam& t : league)
    {
        std::cout << t.teamName << ": " << t.points << " points\n";
    }
    std::cout << '\n';
}

void printBestScorer(const std::vector<footballTeam>& league)
{
    int bestGoals = 0;
    std::string bestName = "no goals scored yet";  

    for (const footballTeam& t : league)
    {
        for (const footballPlayer& p : t.teamPlayers)
        {
            if (p.goalsScored > bestGoals)
            {
                bestGoals = p.goalsScored;   
                bestName = p.playerName;     
            }
        }
    }
    std::cout << "Best scorer: " << bestName << " (" << bestGoals << ")\n\n";
}



int main()
{
    /* Defining all teams */

    footballTeam snake = { "Team Snake" };
    footballTeam ocelot = { "Team Ocelot" };
    footballTeam cobraUnit = { "Team Cobra Unit" };
    footballTeam foxHound = { "Team FoxHound" };

    /* Defining all 4 teams with 3 players each */

    // Team Snake

    footballPlayer nakedSnake;
    nakedSnake.playerName = "Naked Snake";
    nakedSnake.skillsLevel = 15;
    nakedSnake.team = snake.teamName;
    nakedSnake.position = Positions::forward;
    snake.teamPlayers.push_back(nakedSnake);

    footballPlayer solidSnake;
    solidSnake.playerName = "Solid Snake";
    solidSnake.skillsLevel = 10;
    solidSnake.team = snake.teamName;
    solidSnake.position = Positions::goalkeeper;
    snake.teamPlayers.push_back(solidSnake);

    footballPlayer venomSnake;
    venomSnake.playerName = "Venom Snake";
    venomSnake.skillsLevel = 32;
    venomSnake.team = snake.teamName;
    venomSnake.position = Positions::forward;
    snake.teamPlayers.push_back(venomSnake);

    // Team Ocelot

    footballPlayer youngOcelot;
    youngOcelot.playerName = "Young Ocelot";
    youngOcelot.skillsLevel = 15;
    youngOcelot.team = ocelot.teamName;
    youngOcelot.position = Positions::goalkeeper;
    ocelot.teamPlayers.push_back(youngOcelot);

    footballPlayer revolverOcelot;
    revolverOcelot.playerName = "Revolver Ocelot";
    revolverOcelot.skillsLevel = 22;
    revolverOcelot.team = ocelot.teamName;
    revolverOcelot.position = Positions::forward;
    ocelot.teamPlayers.push_back(revolverOcelot);

    footballPlayer oldOcelot;
    oldOcelot.playerName = "Old Ocelot";
    oldOcelot.skillsLevel = 30;
    oldOcelot.team = ocelot.teamName;
    oldOcelot.position = Positions::forward;
    ocelot.teamPlayers.push_back(oldOcelot);

    // Team Cobra Unit

    footballPlayer thePain;
    thePain.playerName = "The Pain";
    thePain.skillsLevel = 24;
    thePain.team = cobraUnit.teamName;
    thePain.position = Positions::forward;
    cobraUnit.teamPlayers.push_back(thePain);

    footballPlayer theSorrow;
    theSorrow.playerName = "The Sorrow";
    theSorrow.skillsLevel = 21;
    theSorrow.team = cobraUnit.teamName;
    theSorrow.position = Positions::goalkeeper;
    cobraUnit.teamPlayers.push_back(theSorrow);

    footballPlayer theFear;
    theFear.playerName = "The Fear";
    theFear.skillsLevel = 27;
    theFear.team = cobraUnit.teamName;
    theFear.position = Positions::forward;
    cobraUnit.teamPlayers.push_back(theFear);

    // Team FoxHound 

    footballPlayer psychoMantis;
    psychoMantis.playerName = "Psycho Mantis";
    psychoMantis.skillsLevel = 27;
    psychoMantis.team = foxHound.teamName;
    psychoMantis.position = Positions::forward;
    foxHound.teamPlayers.push_back(psychoMantis);

    footballPlayer sniperWolf;
    sniperWolf.playerName = "Sniper Wolf";
    sniperWolf.skillsLevel = 29;
    sniperWolf.team = foxHound.teamName;
    sniperWolf.position = Positions::goalkeeper;
    foxHound.teamPlayers.push_back(sniperWolf);

    footballPlayer liquidSnake;
    liquidSnake.playerName = "Liquid Snake";
    liquidSnake.skillsLevel = 44;
    liquidSnake.team = foxHound.teamName;
    liquidSnake.position = Positions::forward;
    foxHound.teamPlayers.push_back(liquidSnake);

    // Defining referee

    referee majorZero;
    majorZero.name = "Major Zero";

    // Grouping all teams together

    std::vector<footballTeam> league;
    league.push_back(snake);
    league.push_back(ocelot);
    league.push_back(cobraUnit);
    league.push_back(foxHound); 

    std::vector<footballMatch> results;

    // Playing all six matches
    for (std::vector<footballTeam>::size_type i = 0; i < league.size(); ++i)
    {
        for (std::vector<footballTeam>::size_type j = i + 1; j < league.size(); ++j)
        {
            printStandings(league);
            printBestScorer(league);
            results.push_back(playGame(league[i], league[j], majorZero));
        }
    }

    // Final output

    std::cout << "**** FINAL STANDINGS ****\n";
    for (const footballTeam& t : league)
    {
        std::cout << t.teamName << ": " << t.points << " points\n";
    }

    std::cout << "\n**** MATCH HISTORY ****\n";
    for (const footballMatch& m : results)
    {
        std::cout << m.teamA << " vs " << m.teamB
            << "  ->  " << m.matchWinner << '\n';
    }

    std::cout << "\nReferee " << majorZero.name
        << " joined " << majorZero.joinedMatches << " matches\n";
}
