USE [MY_DB]
GO
/****** Object:  StoredProcedure [dbo].[updateStuInfo]    Script Date: 07/12/2018 15:06:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[updateStuInfo]
	-- Add the parameters for the stored procedure here
	@nID int,
	@strName nVarChar(30),
	@nAge int
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--SELECT <@Param1, sysname, @p1>, <@Param2, sysname, @p2>
	--更新玩家信息
	UPDATE stu_info SET name = @strName, age = @nAge WHERE num = @nID
END
