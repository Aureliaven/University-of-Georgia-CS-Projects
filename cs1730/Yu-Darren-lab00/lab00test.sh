# CSCI 1730 - Summer 2019 - Lab 0
# Outputs .bash_profile/.bash_login, gcc --version, gdb --version, &
# g++ --version to README

cat ~/.bash_profile > README

# GCC Check
echo -ne "\n" >> README
gcc --version >> README

# GPP Check
echo -ne "\n" >> README
g++ --version >> README

# GDB Check
echo -ne "\n" >> README
gdb --version >> README
