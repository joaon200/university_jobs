use smartfarming;
drop table if exists amostra;
drop table if exists sensores;
drop table if exists user1;

--create tables to save permanently data
create table user1(
	ID int primary key auto_increment not null,
    nome varchar(30) not null,
    pass varchar(30) not null
);
create table sensores(
	ID_P int primary key not null,
    ID_USER int not null,
	foreign key(ID_USER) references user1 (ID) --associate an ESP32 with a user
    on update cascade 
    on delete restrict
);
create table amostra(
	luz int not null,
    temp float not null,
    humidade int not null,
    datahora varchar(19) not null,
    ID_PLACA int not null, 
    primary key (datahora,ID_PLACA),
    foreign key(ID_PLACA) references sensores(ID_P) --linking the data to an ESP32
    on update cascade 
    on delete restrict
);

--insert some data to a database
insert into  user1 (nome, pass) values("joao", "123joao");
insert into  sensores values(1,1),(2,1);
insert into  amostra values(1, 24.5, 60, "2022-05-19/14-47-25",1),(200,25.4, 70, "2022-05-19/14-47-45",2),(1, 24.5, 60, "2022-05-19/14-47-50",2);

select * from user1;
select *from amostra;
select * from sensores;

commit;
