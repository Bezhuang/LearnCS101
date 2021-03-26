package com.alibaba.services;

import java.util.ArrayList;
import java.util.Collection;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
/**
 * @ClassName: Application  
 * 《阿里巴巴Java Spring Boot 2.0开发实战课程》参考代码 完全免费 官方网站 
 * 第7课：Spring Boot2.0安全与MVC身份验证实战(Java面试题) 
 * @author: 阿里巴巴特邀Java专家讲师： 徐雷 Frank Xu Lei 
 */
@Service
public class TaoBaoUserDetailsService implements UserDetailsService {
	private Logger logger = LoggerFactory.getLogger(getClass());
	 
	  @Override
	  public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
	    logger.info("Java Spring Security模拟用户验证: {}", username);
	    Collection<SimpleGrantedAuthority> authorities = new ArrayList<SimpleGrantedAuthority>();
	    authorities.add(new SimpleGrantedAuthority("Admin"));
	    User user = new User(username, "12345678",authorities);
	    return user;
	 }
}
