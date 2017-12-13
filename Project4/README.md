# Project 4 HashTable

## About
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 12/12/17
 * Title: Project 4, HashTable
 
## Building the project

Use `make all` to make the whole project.  Output will be 3.out

## Report on the effectiveness of the djb2 and sdbm hashing methods

Both hashing methods are quite similar in their effectiveness.  sdbm pulls out slightly ahead with less stacked results (had a max of 7 names in the same bucket VS 8 from djb2), and and slightly fewer empty buckets (sdbm had 8 less than djb2).  This testing was based off of the all.lasts.txt file provided.

## Everything else

Everything else is explained when you run the program.
