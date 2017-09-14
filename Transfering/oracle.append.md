# if-then-else
```sql
if [condition] then [statements]
elsif [condition] then [statements]
else [statements]
end if;
```



# deinstall = 卸载
Windows
  \app\aminstrator\product\11.2.0\dbhome_1

# users = 系统用户
sys, system
sysman
scott pw:tiger

# login 用户登录
使用系统用户登录
  [username/password][@server][as sysdba|sysoper]

> system/root @orcl as sysdba
  orcl 是自己设置的服务器名

> connect sys/toor as sysdba

# alter unlock = 启用用户
启用用户的语句
> alter user username account unlock

启用scott用户
> alter user scott account unlock;


# show user = 查看登录用户

# 数据字典 dba_users
dba_users = 查看用户名 系统级别
user_users = 查看用户名 用户级别
dba_tablespaces = 查看用户的表空间 系统级别
user_tablespaces = 查看用户的表空间 用户级别

> select default_tablespace, temporary_tablespace from dba_users where username='SYSTEM'

## 201708230718


# desc = 描述表 查看表属性
> desc dba_users;
