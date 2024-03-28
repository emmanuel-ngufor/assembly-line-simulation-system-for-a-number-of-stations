# Workshop 9: Multi-Threading

In this workshop, you work with a class that represents a Treasure Map that is composed of symbols and characters. A specific character will indicate whether a given spot on the map contains treasure or not. This class will then have its contents written to a binary file and restored from a binary file. Lastly some multithreading will be used to enhance the treasure finding process.

### Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to
- process partitioned data on two or more threads
- write a set of characters to a file in binary mode
- read a set of characters from a file in binary mode
- bind a function to its arguments

## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.



## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

## Part 1 (0%)

The three source files provided for this workshop are
- `TreasureMap.h`   -- already implemented, **do not modify**
- `TreasureMap.cpp` -- partially implemented
- `w9.cpp`         -- already implemented, **do not modify**

The `TreasureMap` class holds three pieces of information:
- The number of rows in the map (rows)
- The size of every row (column size)
- A dynamic array of std::string that will hold the contents of each row (map)

Familiarize yourself with what the already implemented portions of the TreasureMap do.

Your tasks for this part of the workshop are to complete the `enscribe()` and `recall()` member functions of the `TreasureMap` class.  Your code in each case should open the binary file in the appropriate mode and throw an exception if opening fails.

For enscribe(), the process should be as follows:
- Open a binary file stream to the file name provided by the parameter.
- If the stream is in a good state write the number of rows and colSize of the TreasureMap to the file. Note the size of the data type here when writing to the file.
- Afterwards write the rows themselves from the map (ie the dynamic array of std::strings) to the file. When writing each row note that because it is an array of std::strings we should provide the address of the first character of the string to the binary write function. Additionally note the length of the string when writing to the file.

For recall(), the process should be as follows:
- Open a binary file stream to the file name provided by the parameter and use it to populate the current object.
- Read first 4 bytes of the file which will be the number of rows for the map.
- Read second 4 bytes of the file which will be the colSize for the map.
- Afterwards read each row of the map itself
- The reading process here will be very similar to that of the enscribe() function as we're reading back what was written originally
- Be sure to allocate and deallocate memory as needed for the map

### `w9` Module (supplied)

The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.

### Sample Output

When the program is started with the command (the input file is provided):
```
ws map.txt map.bin
```
the output should look like the one from the `sample_output.txt` file.

**:warning:Important:** The output file `map.bin` is not automatically checked; before submission make sure that the file contains binary data (and not the original text). Submissions that do not have binary data in `map.bin` will be rejected.

### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w9_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***





## Part 2 (100%)

Your second task is to multi-thread the findTreasure() member function of the `Treasure Map` class.

The findTreasure() function attempts to locate the presence of any Treasure through the use of the digTreasure() function. digForTreasure operates by taking a reference to an std::string and counting the number of occurences of a particular character (the mark) and returning that count. Refer to the sample_output.txt on what this behavior looks like in action.

Currently findTreasure() uses digForTreasure() by passing each string from the map one at a time. Your task in Part 2 is to upgrade this portion by using threads.

Use at least four (4) threads and partition the data equally amongst those threads. When partitioning the data consider that in this context the data is a set of std::strings. String concatentation may be useful to combine the data for processing.

Use `std::bind` from the `functional` library and placeholders to bind the digForTreasure() function to some of the arguments. Specify the arguments for the placeholders when creating the thread objects.

When binding digForTreasure(), consider the following reference:

  - [std::bind(...)](https://en.cppreference.com/w/cpp/utility/functional/bind)

When providing the task to the threads make use of `std::future` and `std::packaged_task`. As the digForTreasure() function returns a count of found treasure, we will make use of the shared memory space between a future and its provider to store that result (each thread processing a partition of that data to make the total count). The steps to proceed with are:
- Create some packaged_tasks (the number should match the number of threads used) with the bound version of digForTreasure()
- Associate these packaged_tasks with some future objects to eventually retrieve the result of those tasks (ie the count of treasure)
- Create some threads and provided them these packaged_tasks and the partitioned data to be processed
- Retrieve the data from the futures once the threads have completed their tasks

Consider the following reference when working with the packaged_task objects and futures:

  - [std::packaged_task](https://en.cppreference.com/w/cpp/thread/packaged_task)


### `w9` Module (supplied)

The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.

### Sample Output

When the program is started with the command (the input file is provided):
```
ws map.txt map.bin
```
the output should look like the one from the `sample_output.txt` file.

**:warning:Important:** The output file `map.bin` is not automatically checked; before submission make sure that the file contains binary data (and not the original text). Submissions that do not have binary data in `map.bin` will be rejected.

### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- how were binary files used in this workshop, describe the process of using them compared to non binary files
- why would be important to bind a function to its arguments, and how was it useful in this workshop
- the advantages of using multiple threads, and how did you accomplished multi-threading in this workshop
- futures and packaged_tasks were used in the workshop, describe their relationship to one another and how they were used with the threads

To avoid deductions, refer to code in your solution as examples to support your explanations.

### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.  Add switch to your compilation command `-pthread` to enable threading capabilities.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w9_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.