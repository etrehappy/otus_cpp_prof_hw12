#!/bin/sh

BINARY_HOME=./bin
INPUT_HOME=./input
INPUT=${INPUT_HOME}/AB_NYC_2019.csv

# Средняя цена
cat ${INPUT} | ${BINARY_HOME}/mapper | sort -k1 | ${BINARY_HOME}/reducer_mean > output_mean.txt
cat output_mean.txt

# Дисперсия цены
cat ${INPUT} | ${BINARY_HOME}/mapper | sort -k1 | ${BINARY_HOME}/reducer_variance > output_variance.txt
cat output_variance.txt
