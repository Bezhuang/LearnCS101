package com.alibaba.repository;

import java.util.List;

import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.repository.query.Param;

import com.alibaba.models.Users;

public interface UsersRepository extends CrudRepository<Users, Integer> {
 
	@Query("select u from Users u where u.name =?1")
	public List<Users> getUserByName(@Param("name")String name);
	
	@Query("select u from Users u where u.name=?1 and u.password=?2")
	public Users getUserByNameAndPassword(String name, String password);

	@Query("select u from Users u where u.id =?1")
	public Users getUserById(int id);
}
