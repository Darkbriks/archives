#!/bin/bash

# Exercice 1
mkdir tp_unix

touch tp_unix/foo.txt

cd tp_unix
cp foo.txt foo.txt.copy

mv foo.txt.copy foo2

mkdir data
mv foo2 data

mkdir new

mv data/foo2 new

mv new/foo2 foo.old

cd ..
tree -d tp_unix

rm tp_unix/foo.old

rmdir tp_unix/new

# Exercice 2
cd
ls

ls -a

ls -R

ls /dev/*tty*

# Exercice 3
cat /etc/adduser.conf

cat /etc/adduser.conf | more

cat /etc/adduser.conf | less

cat -n /etc/adduser.conf

cat -n /etc/adduser.conf | grep -i group

sudo head /var/log/syslog

sudo tail /var/log/syslog

wc /etc/passwd

wc -l /etc/passwd

# Exercice 4
sudo grep -i kernel /var/log/syslog

grep -i "^#include" /usr/include/c++/8/numeric

grep -i " 13:[0-5][0-9]:[0-5][0-9]" /var/log/syslog

grep -i " 13:[0-5][0-9]:[0-5][0-9]" /var/log/syslog | wc -l

grep -i "error\|warn\|failed" /var/log/messages

grep -i "^ftp" /etc/services

grep -i <nom_utilisateur> /etc/passwd

# Exercice 5
cat /proc/cpuinfo | grep -i "model name\|cpu cores" | head -n 2

cat /proc/meminfo | grep -i "memtotal\|memfree"

ls -l /dev | grep "^c"

lsblk

df -h

free -h

uptime

uname -n

uname -r

# Exercice 6
top

ps -r

top

wget release.ubuntu.com/22.04/ubuntu-22.04-desktop-amd64.iso

ps -e | grep wget

kill <PID>

ps -e | grep cron

# Exercice 7
find /var/log -type f

find /var/log -type f 2>/dev/null

find /var/log -type f 2>/dev/null | sort

find /var/log -type f -size +1M

find /var/log -type f -name "*.gz"

find /var/log -type f -exec grep -l "gnome" {} \; | sort

find /var/log -type f -exec grep -l "gnome" {} \; | sort | xargs grep -c "gnome"

locate nano

locate nano | grep -v "share"

find /usr/share -type f -name "*.sh" -exec wc -l {} \;

# Exercice 8
cd Documents/L2/Archi_3
tar -cvf TP6.tar TP6

gzip TP6.tar

mkdir ~/tmp
mv TP6.tar.gz ~/tmp
cd ~/tmp
tar -xvzf TP6.tar.gz

# Exercice 9
sudo mkdir -p /d_root/a/c/d
sudo mkdir -p /d_root/a/c/e
sudo mkdir -p /d_root/b

touch /d_root/a/c/e/file.txt

sudo chown student /d_root/a/c/e

sudo touch /d_root/a/c/d/file.txt

nano /d_root/a/c/d/file.txt

sudo chmod 777 /d_root/a/c/d/file.txt
nano /d_root/a/c/d/file.txt

sudo chmod 000 /d_root/b
touch /d_root/b/file.txt

# Exercice 10
mkdir ~/tmp
cd ~/tmp
wget https://www.gnu.org/licenses/gpl-3.0.txt 2>&1

sed 's/2007/2021/' gpl-3.0.txt > gpl-4.0.txt

diff gpl-3.0.txt gpl-4.0.txt

sed 's/version 3/version 4/g' gpl-4.0.txt > gpl-4.1.txt
sed -i 's/Version 3/Version 4/g' gpl-4.1.txt

diff gpl-4.0.txt gpl-4.1.txt

sed 's/\([0-9]\+\)\. /\[\1\] /g' gpl-4.1.txt > gpl-4.2.txt
diff gpl-4.1.txt gpl-4.2.txt

# Exercice 11
mkdir ~/tmp
cd ~/tmp
echo '# include <iostream>' > main.cpp
echo 'int main() {' >> main.cpp
echo 'std::cout << "Hello" << std::endl;' >> main.cpp
echo 'return 0;' >> main.cpp
echo '}' >> main.cpp
g++ main.cpp -o main
./main

cd
export PATH=$PATH:~/tmp
main

echo "alias ll='ls -l'" >> .bashrc
ll

source ~/.bashrc

echo "PS1='\t \u@\h:\w\$ '" >> .bashrc
source ~/.bashrc

# Exercice 12
echo "Arne 182 0\nMarie 190 0\nVishal 213 150\nGrete 192 16\nFinn 192 37\nKari 220 145\nArnfinn 220 150\nTorstein 250 132\nTrude 196 150\nGeir 160 13\nHoda 196 42" > salaires.txt

awk '{ if ($3 > 0) { salaire = $2 * $3; print $1, salaire } }' salaires.txt

awk '{ if ($2 > 200) { print $1 } }' salaires.txt

awk '{ if (length($1) > 6) { print } }' salaires.txt

awk 'BEGIN { count = 0 } { count++ } END { print count }' salaires.txt