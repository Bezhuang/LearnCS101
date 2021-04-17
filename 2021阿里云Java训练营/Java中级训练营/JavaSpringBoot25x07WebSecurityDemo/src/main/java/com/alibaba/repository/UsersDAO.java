package com.alibaba.repository;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.springframework.stereotype.Repository;

import com.alibaba.models.Users;

@Repository
@Mapper
public interface UsersDAO {

	    @Insert({"insert into users(name, password) values (#{name},#{password})"})
	    int addUser(Users user);
	    
	    @Select({"select * from users order by id desc"})
	    List<Users> getAllUsers();
	    
	    @Select({"select * from users where name = #{name}"})
	    Users getUserByName(String name);
	    
	    @Select({"select * from users where id = #{id}"})
	    Users getUserById(int id);
	    
	    @Select({"select * from users where name = #{name} and password = #{password}"})
		Users getUserByNameAndPassword(String name, String password);

	    @Update({"update users set password = #{password} where name = #{name}"})
	    void updateUser(Users user);
	    
	    @Delete({"delete from users where id = #{id}"})
	    void deleteUser(int id);
}
