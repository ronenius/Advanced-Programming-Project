כדי להריץ, יש פשוט לקרוא למיין, והתוכנית תרוץ עם
k==5
כדי לשנות את
k
יש להגדיר לו ערך שונה בשורה 5 של המיין.
לא נעשו אופטימיזציות משמעותיות. סיבוכיות האלגוריתם היא
O(k^2*n)
המימוש הוא
1. קריאה מהקבצים
2. מציאת
   k
   הפרחים הכי קרובים על ידי מציאת הכי קרוב בכל פעם.
3. מציאת הסוג הנפוץ ביותר בין הפרחים שנבחרו.
4. לחזור על התהליך מ 2 עבור כל אחד מהפרחים הלא מסווגים
5. לכתוב לקובץ הפלט.