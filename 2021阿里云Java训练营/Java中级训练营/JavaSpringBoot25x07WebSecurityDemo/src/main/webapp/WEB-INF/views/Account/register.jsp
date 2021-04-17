<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>

<jsp:include page="head.jsp"></jsp:include>
<br>
<div class="container" style="max-width: 450px;">
	<form class="form-signin"  action="./register" method="post">
		<h2
			style="text-align: center; font-family: Microsoft YaHei;">注册新用户</h2>
		<div class="form-group">
			<label for="name">账号</label> 
			<input type="text" class="form-control"
				id="username" name="username" placeholder="手机号或email"  required />
		</div>

		<div class="form-group">
			<label for="password">密码</label> <input type="password"
				class="form-control" id="password" name="password" placeholder="密码" required autofocus>
		</div>

		<div class="form-group">
			<label for="passwordConfirm">确认密码</label> <input type="password"
				class="form-control" id="passwordConfirm" name="passwordConfirm" placeholder="确认密码" required>
		</div>

		<button type="submit" onclick="return checkPassword();"  class="btn btn-primary form-control">注册</button>
	</form>
</div>
<script type="text/javascript">
   function checkPassword()
   {
	   var pasword = document.getElementById("password").value;
	   var passwordConfirm = document.getElementById("passwordConfirm").value;

	   if(pasword==passwordConfirm)
	   {
		   return true;
	   }else
	   {
		   alert("两次密码不一样，请重新输入");
		   document.getElementById("password").focus();
		   return false;
	   }
	   
   }
</script>
<jsp:include page="foot.jsp"></jsp:include>