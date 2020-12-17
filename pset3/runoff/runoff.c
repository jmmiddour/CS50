#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Create variable to hold candidate index value
    int cand_index = -1;
    
    // Create for loop to iterate over the list of candidate names
    for (int i = 0; i < candidate_count; i++)
    {
        // If the input is the same as a candidate in the list
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Grab index value for candidate
            cand_index = i;
            
            // Update preference
            preferences[voter][rank] = cand_index;
            return true;
        }
    }
    
    // If input does not match a candidate in the list
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate through voter index
    for (int i = 0; i < voter_count; i++)
    {
        // Iterate through candidate index
        for (int j = 0; j < candidate_count; j++)
        {
            // Assign a variable to pull out the candidate index
            int pref_cand_ind = preferences[i][j];
            
            // Make sure candidate has not been eliminated
            if (!candidates[pref_cand_ind].eliminated)
            {
                // Increment the vote count for non-eliminated candidates
                candidates[pref_cand_ind].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Iterate through candidate votes to find winner
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if any candidates have at least 50% of votes
        if (candidates[i].votes > voter_count / 2)
        {
            // Print winner's name with > 50% of votes
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    
    // If no winners with > 50% of votes
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Determine the largest number of votes
    int min_num = MAX_VOTERS * MAX_CANDIDATES + 1000;
        
    // Iterate through candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        // Find candidates not eliminated and votes < min
        if (!candidates[i].eliminated && candidates[i].votes < min_num)
        {
            // Update min_num with each iteration until if statement returns false
            min_num = candidates[i].votes;
        }
    }
    
    // Return updated min number of votes
    return min_num;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Iterate through candidate_count
    for (int i = 0; i < candidate_count; i++)
    {
        // Find if there is any non-eliminated candidates > min
        if (candidates[i].votes > min && !candidates[i].eliminated)
        {
            // If there is votes > min, then there is no tie, return false
            return false;
        }
    }
    // If no votes > min, there is a tie, return true
    return true; 
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Iterate through candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        // Determine if vote count == min votes
        if (candidates[i].votes == min)
        {
            // Update the eliminated value if the above is true for candidate
            candidates[i].eliminated = true;
        }
    }
    return;
}
