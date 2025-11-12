#!/bin/bash

export PLANTUML_JAR=~/plantuml.jar

lualatex -shell-escape main.tex     # Creates bibliography
biber main                          # Fills bibliography
lualatex -shell-escape main.tex     # Generates finished PDF