import csv

# Open TSV file
# https://datasets.imdbws.com/title.basics.tsv.gz
with open("title.basics.tsv", "r") as titles:

    # Create DictReader
    reader = csv.DictReader(titles, delimiter="\t")  # \t tells the computer that this is a TSV (Tab Seperaated Values) file

    # Open CSV file
    with open("shows0.csv", "w") as shows:  # Creates a new csv file to write specified data to.

        # Create writer - a variable to write to the csv file
        writer = csv.writer(shows)

        # Write header using `writerow` (writes a row of data to the csv)
        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"])

        # Iterate over TSV file
        for row in reader:

            # If non-adult TV show
            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":

                # Write row
                writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]])
