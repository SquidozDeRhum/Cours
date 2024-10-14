# TP7 Synthèse sur les filtres

Q1. egrep '24/DEC/2020' -i -c < access.log

Q2. egrep '24/DEC/2020:18:[0-5][0-9]' -i  -c< access.log

Q3. egrep ':18:[0-5][0-9]:' -i  -c < access.log

Q4. egrep ':18:[0-2][0-9]:' -i  -c < access.log

Q5. egrep '(:09:[0-2][0-9]:[0-5][0-9])|(9:30:00)' -i  -c < ac
cess.log

Q6. cut -d '[' -f 2 < access.log | cut -d ':' -f 1 | uniq

Q7. cut -d '[' -f 2 < access.log | cut -d ':' -f 1 | uniq

Q8. cut -d ' ' -f 1 < access.log | sort | uniq -c | sort -rn | head -1

Q9.