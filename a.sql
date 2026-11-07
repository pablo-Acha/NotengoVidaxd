CREATE INDEX idx_rental_date
ON rental (rental_date);ANALYZE rental;

EXPLAIN (ANALYZE, BUFFERS)
SELECT *
FROM rental
WHERE rental_date BETWEEN '2005-07-01' AND '2005-07-31';

SELECT
   relname,
   last_analyze,
   analyze_count

ANALYZE;


CREATE INDEX idx_peliculas_datos_gin
ON peliculas_streaming
USING GIN (datos);



EXPLAIN ANALYZE
SELECT plataforma, datos
FROM peliculas_streaming
WHERE datos @> '{"genero":["Drama"]}';




EXPLAIN ANALYZE
SELECT plataforma, datos
FROM peliculas_streaming
WHERE datos @> '{
"idioma":"Ingles",
"anio":2021
}';


UPDATE rental
SET staff_id = 1
WHERE rental_id <= 1000;
DELETE FROM rental
WHERE rental_id <= 10;

SELECT
   relname,
   n_live_tup,
   n_dead_tup
FROM pg_stat_user_tables
WHERE relname = 'rental';
