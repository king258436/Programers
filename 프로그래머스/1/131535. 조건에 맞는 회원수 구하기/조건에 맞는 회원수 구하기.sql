-- 코드를 입력하세요
SELECT COUNT(user_id) as USERS
FROM USER_INFO
WHERE YEAR(joined) = '2021' AND age >=20 && age<=29;