[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11298274&assignment_repo_type=AssignmentRepo)
# Assignment 1

# Instructions    

## Data
Write a program in C++ that asks the user for the names of 2 files:
1.  The data file
    * This will contain a table of field names and their values.
    * The field names will be in the first row.  there should be no spaces between field names and commas.
    *      x,y,z is ok.  x,  y,  z is not.
    * *Field names will be single words only and in lower case*
    * Values will be separated by commas and may contain spaces
    * Each row will be on a single line.
    * Every file should have an Id field, named Id
    
    Example:
     ```None
     id, last,first,address1,city,state,zipcode
     1,Schoeneman,Larry, 1234 e anywhere dr, palatine, IL, 60074
     2,Smith,Bob, 456 anywhere else dr, mt prospect, IL, 60056 
     ```   
2.  The merge file:
     * The merge file will contain a mail merge file.  
     * When you see %fieldname%, you should replace it with the value of field name.
     * *Fieldnames must be lowercase only*

     Example:
     ```C++
     Hello %first%,     
     
     We've been working with other families in %city% to repair roof damage from the latest storm.     
     Your home at %address1% appears to have damage.       
     Please contact us at 123-446-1231 to schedule a free inspection
     
     Thank you,
     Annoying Contractors
     ```   


## Program Details
* Given the files above, you should run the mail merge once per each row in the data file.  
* Output a single file for each user containing the merged results.  The name of the file should be <Id>.txt where Id is the id of the row
* Print the generated file name to the console.
* Print the total number of records processed to the console.
  
  The basic algorithm should look something like this:

  ```C++
  Get data file name
  Get merge file name
  Parse the data file header (1st row) to get the field names
    - Consider reading in the header, splitting the fields and storing them in an array    
  For each data row
     Split the data row into an array
     For each occurrence of a field name in the merge file
        Find the field in the header array
            Using that field's position, look it up in the current row
            Replace the field name with the value in the merge file
  Write the merged file to disk and name it <id>.txt
  ```
  
  
 ## Sample Run
* Given the sample files above, a sample run would look like this.
 ```
  Enter the data file name: mydata.txt
  Enter to merge file name: merge.txt
  
  1.txt merged
  2.txt merged
  
  Merge Complete.  2 files generated.
  ```
# File output
  
## File: 1.txt
```
     Hello Bob,     
     We've been working with other families in mt prospect to repair roof damage from the latest storm.     
     Your home at 456 anywhere else dr appears to have damage.       
     Please contact us at 123-446-1231 to schedule a free inspection
     
     Thank you,
     Annoying Contractors
```
  
 ## File: 2.txt
```
     Hello Larry,     
     We've been working with other families in palatine to repair roof damage from the latest storm.     
     Your home at 1234 e anywhere dr appears to have damage.       
     Please contact us at 123-446-1231 to schedule a free inspection
     
     Thank you,
     Annoying Contractors
```

## TIPS:
  1.  Make sure to follow the coding standards document.  It is available on blackboard and in this repository.  You will lose points if you don't.
  2.  **The input and output should match the sample executable precisely.  No embellishments.  Do what the problem description says, and do only that.  Otherwise there will be point penalties.**
  3.  **MAKE SURE TO PUT THE APPROPRIATE HEADER IN YOUR PROGRAM AS SPECIFIED IN THE CODING STANDARDS DOC IN THIS REPOSITORY**
  4.  Adequately test your code under a variety of different scenarios.
