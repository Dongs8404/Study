CREATE TABLE `my_community`.`user` (
  `user_id` VARCHAR(50) NOT NULL,
  `age` INT UNSIGNED NULL,
  `nickname` VARCHAR(200) NULL,
  `email` VARCHAR(200) NULL,
  `password` VARCHAR(300) NULL,
  `created_at` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`user_id`)); -- 테이블생성 명령

show databases; -- 데이터베이스 목록 조회
use my_community; -- 사용할 데이터베이스 스키마 선택
show tables; -- 선택된 스키마의 테이블 목록 조회
select * from user; -- user 테이블의 전체 데이터 조회

-- 데이터 입력
insert into user (user_id, age, nickname) values ('abc', 28, '테스트');
INSERT INTO `my_community`.`user` (`user_id`, `age`, `nickname`) VALUES ('wow', '55', '개쩌네');