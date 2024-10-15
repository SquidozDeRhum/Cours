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

Q9. egrep '^([0-9]{1,3})\.[0-9]{1,3}\.\1\.[0-9]{1,3}' < access.log

Q10. egrep 'HTTP/.{5}200' -c < access.log

Q11. egrep 'HTTP/.{5}200' -v < access.log | cut -d ' ' -f 6-10 | sort | uniq -c | sort -n

Q12. egrep '([0-9]{2}:)\1\1' < access.log 

Q13. egrep '(GET)|(POST)' -v < access.log

Q14. egrep '\- \-' -v <access.log

Q15. egrep '\- \-' -v <access.log | cut -d ' ' -f 3,6,7,10

Q99. cut -d ' ' -f 10 < access.log | tr '\n' '+' | rev | cut -c2- | rev | bc