
############ WITH RECURSIVE 앞에 인덱스 ############

WITH RECURSIVE time as (SELECT 9 AS hour
                        UNION ALL
                        SELECT hour + 1 FROM time WHERE hour < 19)
SELECT T.hour AS HOUR, COUNT(A.ANIMAL_ID) AS COUNT
    FROM ANIMAL_OUTS AS A JOIN
        time AS T
        ON hour(A.DATETIME) = T.hour
    GROUP BY T.hour
    ORDER BY T.hour



############ 분야별 최댓값 뽑기 ############

SELECT R.FOOD_TYPE, R.REST_ID, R.REST_NAME, R.FAVORITES
    FROM REST_INFO AS R JOIN
        (SELECT FOOD_TYPE, MAX(FAVORITES) AS FAVORITES
          FROM REST_INFO
          GROUP BY FOOD_TYPE
         ) AS F
        ON R.FAVORITES = F.FAVORITES AND R.FOOD_TYPE = F.FOOD_TYPE
    # WHERE R.FAVORITES = F.FAVORITES
    ORDER BY FOOD_TYPE DESC

SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME
    FROM FOOD_PRODUCT
    WHERE PRICE IN
        (SELECT MAX(PRICE) AS PRICE
         FROM FOOD_PRODUCT 
         GROUP BY CATEGORY
        )
        AND CATEGORY IN ('과자', '국', '김치', '식용유')
    ORDER BY PRICE DESC



############ 몇개 이상 뽑기 ############
SELECT P.ID, P.NAME, P.HOST_ID
    FROM PLACES AS P JOIN
        (SELECT HOST_ID, COUNT(ID)
         FROM PLACES
         GROUP BY HOST_ID
         HAVING COUNT(ID) >= 2
        ) AS C
        ON P.HOST_ID = C.HOST_ID
    ORDER BY ID




############ CASE WHEN 셀렉트 정하기 ############
SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, "%Y-%m-%d"), 
                                        CASE WHEN OUT_DATE <= "2022-05-01" THEN "출고완료"
                                            WHEN OUT_DATE > "2022-05-01" THEN "출고대기"
                                            ELSE "출고미정"
                                            END AS "출고여부"
    FROM FOOD_ORDER
    ORDER BY ORDER_ID
