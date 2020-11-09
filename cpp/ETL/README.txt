Whomever it may concern,

This ETL folder was made as I went through the ETL.cpp exercise in Exercism.io
In this exercise, I was tasked with taking an old system of Scrabble(c), 
where the letters were in lists according to their number, and perform an
ETL procedure on it (Extract-Transform-Load). 

This ETL process would have to take the old system and convert it to a new system
that connects the letters with corresponding numbers. In Python, I would have just 
used dictionaries to pair a letter with a score; however, I wasn't too familiar with
C++ alternatives, so I converted the old system scores into a 26-int vector and 
matched the index values with a 26-char alphabet string.

The rest is history...

There are three files:
ETL_extract-transform.cpp // Converts the old system into the 26-int vector stored in scores.txt
ETL_load.cpp // Loads the 26-int vector into the 'new system' and runs the Scrabble program
ETL_complete.cpp // The whole ETL cycle with extraction, transformation, and loading
