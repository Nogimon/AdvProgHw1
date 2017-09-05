//For runing the program
To run the program, simply make the Makefile and run the hw1.out file:

make -f Makefile
(run 'chmod +x hw1.out' if without permisson )
./hw1.out

(I have tried it successfully on Linux and on Sunlab, but I am not sure if it works on Mac)

//For data input
Data is preserved in two txt files and separeted by lines:
Single t test data is in input.txt
Paired t test data is in pairinput.txt
If change to data is needed, just do the change in the txt file.
And if only one of the t tests is needed, just delete the other file and the program will jump over the task.

//For output
t value is calculated through the program. 
Yet since the size of the data is changeble, so the P value of the result can change with the size. So I didn't attach the full chart into it so no P value or judgement will be generated through the program.