# pge2-d2_srm_decomposition

This repository contains a minimum executable C++ example for prostaglandin E2 and D2 deconvolution from a set of selected ion monitoring (SRM) for four transitions.  It is intended to demonstrate how the obtained product ion spectra (four intensities on SRM transitions from <I>m/z</i> 351->233, 351->271, 351->315, and 351->333.

## Prerequisit
1. C++20-compliant C++ compiler and related tool chains
2. CMake
3. Eigen 3.4.0 (https://eigen.tuxfamily.org/index.php?title=Main_Page)

## Build steps
1. Make a directory for build wherever you are comfortable.
2. Run cmake as cmake <directory where git-repo has been obtained>
  Assume the git repo was cloned under your ~/src/ directory like:
   ~~~bash
   cd ~/src
   git clone https://github.com/qtplatz/pge2-d2_srm_decomposition
   cd ~/work
   mkdir build
   cd build
   cmake ~/src/pge2-d2_srm_decomposition
   cmake --build .
   ~~~
   
