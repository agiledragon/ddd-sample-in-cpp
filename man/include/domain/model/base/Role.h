#ifndef H895728F5_B760_48DD_8B78_45BA136552AF
#define H895728F5_B760_48DD_8B78_45BA136552AF


#define ROLE(role) get##role()
#define ROLE_PROTO_TYPE(role) role& ROLE(role) const
#define USE_ROLE(role) virtual ROLE_PROTO_TYPE(role) = 0
#define HAS_ROLE(role) USE_ROLE(role)

#define IMPL_ROLE(role)                                       \
ROLE_PROTO_TYPE(role) override                                \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

#define IMPL_ROLE_WITH_TYPE(role, type)                       \
ROLE_PROTO_TYPE(role) override                                \
{                                                             \
   return const_cast<type&>(static_cast<const type&>(*this)); \
}

#define __TYPE_VAR(type) type##var

#define IMPL_ROLE_WITH_VAR(role, type)             \
private:                                           \
   ROLE_PROTO_TYPE(role)  override                 \
   { return const_cast<type&>(__TYPE_VAR(type)); } \
   type __TYPE_VAR(type)

#define __ROLE_VAR(role) role##var

#define IMPL_ROLE_WITH_ROLE_VAR(role)         \
private:                                      \
   ROLE_PROTO_TYPE(role) override             \
   { return const_cast<role&>(role##var); }   \
   role __ROLE_VAR(role)


#define ROLE_PTR(RoleType) RoleType##__
#define SET_ROLE(RoleType)  set##RoleType

#define DECL_ROLE(role) ROLE_PROTO_TYPE(role)

#define EXPORT_ROLE(role) USE_ROLE(role)

#define __ROLE_CAST_TO(role, obj)       \
    return const_cast<role&>(static_cast<const role&>(obj))

#define IMPL_ROLE_WITH_OBJ(role, obj)   \
    DECL_ROLE(role)  { __ROLE_CAST_TO(role, obj); }

#define DECL_DEPENDENCY(RoleType)                             \
public:                                                       \
    void SET_ROLE(RoleType)(RoleType& role)                   \
    { ROLE_PTR(RoleType) = &role; }                           \
    DECL_ROLE(RoleType)                                       \
    { return *(const_cast<RoleType*>(ROLE_PTR(RoleType))); }  \
private:                                                      \
    RoleType* ROLE_PTR(RoleType)

#define DECL_OBJECT_ROLE(Object, RoleType) \
    RoleType& Object::get##RoleType() const


struct Role
{
	virtual ~Role() = default;
};


#define SELF(self, role) static_cast<role&>(self)
#define SELF_P(self, role) SELF(*self, role)
#define SELF_CONST(self, role) static_cast<const role&>(self)


#endif
