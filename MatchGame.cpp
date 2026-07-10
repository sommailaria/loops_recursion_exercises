
#include <iostream>
#include <string>
#include <vector>

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

    void scoreGoals(int n)
    {
        goalsScored += n;
    }

    void playMatch()
    {
        ++matchesPlayed;
    }
};

class footballTeam
    
{
public:
    std::string teamName{};
    std::vector<footballPlayer> teamPlayers{};
    int points{};

    
    int keeperSkill()
    {
        for (const footballPlayer& p : teamPlayers)
        {
            if (p.position == Positions::goalkeeper)
            {
                return p.skillsLevel;
            }
        }
        return 0;
    }

    // Playing the game

    int attack(int enemyKeeperSkill)
    {
        int goals = 0;
        for (footballPlayer& p : teamPlayers)
        {
            if (p.position == Positions::forward)
            {
                if (p.skillsLevel >= 30)
                {
                    p.scoreGoals(2);        
                    goals += 2;             
                }
                else if (p.skillsLevel > enemyKeeperSkill)
                {
                    p.scoreGoals(1);
                    goals += 1;
                }
            }
            p.playMatch();                  
        }
        return goals;
    }

    void addPoints(int n)
    {
        points += n;
    }
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

    void joinMatch()          
    {
        ++joinedMatches;
    }
};


footballMatch playGame(footballTeam& teamA, footballTeam& teamB, referee& ref)
{
    int goalsA = teamA.attack(teamB.keeperSkill());
    int goalsB = teamB.attack(teamA.keeperSkill());

    footballMatch record;
    record.teamA = teamA.teamName;
    record.teamB = teamB.teamName;

    if (goalsA > goalsB)
    {
        teamA.addPoints(3);
        record.matchWinner = teamA.teamName;
    }
    else if (goalsB > goalsA)
    {
        teamB.addPoints(3);
        record.matchWinner = teamB.teamName;
    }
    else
    {
        teamA.addPoints(1);
        teamB.addPoints(1);
        record.matchWinner = "Draw";
    }

    ref.joinMatch();
    return record;
}

// These stay free: they operate on the whole league, and the league
// is a plain std::vector — not a type of ours to put functions into.
void printStandings(const std::vector<footballTeam>& matches)
{
    std::cout << "--- Standings ---\n";
    for (const footballTeam& t : matches)
    {
        std::cout << t.teamName << ": " << t.points << " points\n";
    }
    std::cout << '\n';
}

void printBestScorer(const std::vector<footballTeam>& matches)
{
    int bestGoals = 0;
    std::string bestName = "no goals scored yet";

    for (const footballTeam& t : matches)
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
    /* Teams */

    footballTeam snake = { "Team Snake" };
    footballTeam ocelot = { "Team Ocelot" };
    footballTeam cobraUnit = { "Team Cobra Unit" };
    footballTeam foxHound = { "Team FoxHound" };

    /* Players  */

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

    footballPlayer liquidOcelot;
    liquidOcelot.playerName = "Old Ocelot";
    liquidOcelot.skillsLevel = 30;
    liquidOcelot.team = ocelot.teamName;
    liquidOcelot.position = Positions::forward;
    ocelot.teamPlayers.push_back(liquidOcelot);

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

    referee majorZero;
    majorZero.name = "Major Zero";

    std::vector<footballTeam> allMatches;
   allMatches.push_back(snake);
   allMatches.push_back(ocelot);
   allMatches.push_back(cobraUnit);
   allMatches.push_back(foxHound);

    

    std::vector<footballMatch> results;

    for (std::vector<footballTeam>::size_type i = 0; i < allMatches.size(); ++i)
    {
        for (std::vector<footballTeam>::size_type j = i + 1; j < allMatches.size(); ++j)
        {
            printStandings(allMatches);
            printBestScorer(allMatches);
            results.push_back(playGame(allMatches[i], allMatches[j], majorZero));
        }
    }

    std::cout << "****** FINAL STANDINGS ******\n";
    for (const footballTeam& t : allMatches)
    {
        std::cout << t.teamName << ": " << t.points << " points\n";
    }

    std::cout << "\n****** MATCH HISTORY ******\n";
    for (const footballMatch& m : results)
    {
        std::cout << m.teamA << " vs " << m.teamB
            << "  ->  " << m.matchWinner << '\n';
    }

    std::cout << "\nReferee " << majorZero.name
        << " joined " << majorZero.joinedMatches << " matches\n";
}
