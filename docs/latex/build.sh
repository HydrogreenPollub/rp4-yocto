#!/bin/bash

mkdir -p build

lualatex -shell-escape -output-directory=build main.tex     # Creates bibliography
biber --input-directory build --output-directory build main # Generates bibliography
lualatex -shell-escape -output-directory=build main.tex     # Generates finished PDF