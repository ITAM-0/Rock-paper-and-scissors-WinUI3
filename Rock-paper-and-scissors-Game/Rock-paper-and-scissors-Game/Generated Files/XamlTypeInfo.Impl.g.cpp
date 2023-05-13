﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"

#include <memory>
#include <string>
#include <regex>
#include <unknwn.h>
#include <mutex>
#include "winrt/windows.foundation.h"
#include "winrt/windows.ui.xaml.interop.h"
#include "winrt/microsoft.ui.xaml.markup.h"
#include "XamlTypeInfo.xaml.g.h"
#include "XamlMetaDataProvider.h"

namespace winrt::Rock_paper_and_scissors_Game::implementation
{
    using namespace ::winrt::Microsoft::UI::Xaml::Markup;
    using namespace ::winrt::Windows::UI::Xaml::Interop;

    // XamlMetaDataProvider


    IXamlType XamlMetaDataProvider::GetXamlType(TypeName const& type)
    {
        return Provider()->GetXamlTypeByType(type);
    }

    IXamlType XamlMetaDataProvider::GetXamlType(::winrt::hstring const& fullName)
    {
        return Provider()->GetXamlTypeByName(fullName);
    }

    ::winrt::com_array<XmlnsDefinition> XamlMetaDataProvider::GetXmlnsDefinitions()
    {
        return ::winrt::com_array<XmlnsDefinition>(0);
    }

    std::shared_ptr<XamlTypeInfoProvider> XamlMetaDataProvider::Provider()
    {
        if (!_provider)
        {
            _provider = std::make_shared<XamlTypeInfoProvider>();
        }
        return _provider;
    }

    // XamlTypeInfoProvider

    IXamlType XamlTypeInfoProvider::GetXamlTypeByType(TypeName const& type)
    {
        auto xamlType = GetXamlTypeByName(type.Name);
        auto userXamlType = xamlType ? xamlType.try_as<IXamlUserType>() : nullptr;
        if (!xamlType || (userXamlType && userXamlType->IsReturnTypeStub() && !userXamlType->IsLocalType()))
        {
            auto libXamlType = CheckOtherMetadataProvidersForType(type);
            if (libXamlType)
            {
                if (libXamlType.IsConstructible() || !xamlType)
                {
                    xamlType = libXamlType;
                }
            }
        }
        return xamlType;
    }

    IXamlType XamlTypeInfoProvider::GetXamlTypeByName(::winrt::hstring const& typeName)
    {
        if (typeName.empty())
        {
            return nullptr;
        }

        std::lock_guard<std::recursive_mutex> lock(_xamlTypesCriticalSection);
        auto val = _xamlTypes.find(typeName.data());
        if (val != _xamlTypes.end())
        {
            auto xamlType = (val->second).get();
            if (xamlType)
            {
                return xamlType;
            }
        }

        auto xamlType = CreateXamlType(typeName);
        auto userXamlType = xamlType ? xamlType.try_as<IXamlUserType>() : nullptr;
        if (!xamlType || (userXamlType && userXamlType->IsReturnTypeStub() && !userXamlType->IsLocalType()))
        {
            IXamlType libXamlType = CheckOtherMetadataProvidersForName(typeName);
            if (libXamlType)
            {
                if (libXamlType.IsConstructible() || !xamlType)
                {
                    xamlType = libXamlType;
                }
            }
        }

        if (xamlType)
        {
            _xamlTypes.insert_or_assign(xamlType.FullName().data(), xamlType);
        }
        return xamlType;
    }

    IXamlMember XamlTypeInfoProvider::GetMemberByLongName(::winrt::hstring const& longMemberName)
    {
        if (longMemberName.empty())
        {
            return nullptr;
        }

        std::lock_guard<std::recursive_mutex> lock(_xamlMembersCriticalSection);
        auto val = _xamlMembers.find(longMemberName.data());
        if (val != _xamlMembers.end())
        {
            return val->second;
        }

        auto xamlMember = CreateXamlMember(longMemberName);

        if (xamlMember)
        {
            _xamlMembers.insert_or_assign(longMemberName.data(), xamlMember);
        }
        return xamlMember;
    }

    IXamlType XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::winrt::hstring const& typeName)
    {
        IXamlType foundXamlType;
        std::lock_guard<std::recursive_mutex> lock(_xamlTypesCriticalSection);
        for (auto const& provider : OtherProviders())
        {
            auto xamlType = provider.GetXamlType(typeName);
            if (xamlType)
            {
                if (xamlType.IsConstructible())
                {
                    return xamlType;
                }
                foundXamlType = xamlType;
            }
        }
        return foundXamlType;
    }

    IXamlType XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(TypeName const& t)
    {
        IXamlType foundXamlType;
        std::lock_guard<std::recursive_mutex> lock(_xamlTypesCriticalSection);
        for (auto const& provider : OtherProviders())
        {
            auto xamlType = provider.GetXamlType(t);
            if (xamlType)
            {
                if (xamlType.IsConstructible())
                {
                    return xamlType;
                }
                foundXamlType = xamlType;
            }
        }
        return foundXamlType;
    }

    // XamlSystemBaseType

    XamlSystemBaseType::XamlSystemBaseType(::winrt::hstring const& name)
        : _fullName(name)
    {
    }

    IXamlType XamlSystemBaseType::BaseType() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    IXamlMember XamlSystemBaseType::ContentProperty() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    ::winrt::hstring XamlSystemBaseType::FullName() const
    {
        return _fullName;
    }

    ::winrt::hstring XamlSystemBaseType::Name() const
    {
        const wchar_t* separator = wcsrchr(_fullName.c_str(), '.');
        if (!separator)
        {
            return _fullName;
        }
        return ::winrt::hstring { separator };
    }

    bool XamlSystemBaseType::IsArray() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsCollection() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsConstructible() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsDictionary() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsMarkupExtension() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsEnum() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsSystemType() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    bool XamlSystemBaseType::IsBindable() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    IXamlType XamlSystemBaseType::ItemType() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    IXamlType XamlSystemBaseType::KeyType() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    IXamlType XamlSystemBaseType::BoxedType() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    TypeName XamlSystemBaseType::UnderlyingType() const
    {
        return { _fullName, TypeKind::Primitive };
    }

    ::winrt::Windows::Foundation::IInspectable XamlSystemBaseType::ActivateInstance() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    IXamlMember XamlSystemBaseType::GetMember(::winrt::hstring const& ) const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    void XamlSystemBaseType::AddToVector(::winrt::Windows::Foundation::IInspectable const&, ::winrt::Windows::Foundation::IInspectable const&) const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    void XamlSystemBaseType::AddToMap(::winrt::Windows::Foundation::IInspectable const&, ::winrt::Windows::Foundation::IInspectable const&, ::winrt::Windows::Foundation::IInspectable const&) const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    void XamlSystemBaseType::RunInitializer() const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    ::winrt::Windows::Foundation::IInspectable XamlSystemBaseType::CreateFromString(::winrt::hstring const& ) const
    {
        throw ::winrt::hresult_not_implemented {};
    }

    // XamlUserType

    XamlUserType::XamlUserType(
        std::shared_ptr<XamlTypeInfoProvider> const& provider, 
        ::winrt::hstring const& fullName, 
        IXamlType baseType)
            : _provider(provider)
            , _fullName(fullName)
            , _baseType(baseType)
    {
    }

    ::winrt::hstring XamlUserType::GetRuntimeClassName() const
    {
        static ::winrt::hstring name{ ::winrt::name_of<::winrt::Microsoft::UI::Xaml::Markup::IXamlType>() };
        return name;
    }

    ::winrt::hstring XamlUserType::FullName() const
    {
        return _fullName;
    }

    ::winrt::hstring XamlUserType::Name() const
    {
        const wchar_t* separator = wcsrchr(_fullName.c_str(), '.');
        if (!separator)
        {
            return _fullName;
        }
        return separator;
    }

    TypeName XamlUserType::UnderlyingType() const
    {
        return { _fullName, _kindOfType };
    }

    bool XamlUserType::IsSystemType() const
    {
        return true;
    }

    IXamlType XamlUserType::BaseType() const
    {
        return _baseType;
    }

    bool XamlUserType::IsArray() const
    {
        return _isArray;
    }

    void XamlUserType::IsArray(bool value)
    {
        _isArray = value;
    }

    bool XamlUserType::IsCollection() const
    {
        return _collectionAdd;
    }

    bool XamlUserType::IsConstructible() const
    {
        return _activator;
    }

    bool XamlUserType::IsDictionary() const
    {
        return _dictionaryAdd;
    }

    bool XamlUserType::IsMarkupExtension() const
    {
        return _isMarkupExtension;
    }

    void XamlUserType::IsMarkupExtension(bool value)
    {
        _isMarkupExtension = value;
    }

    bool XamlUserType::IsEnum() const
    {
        return _isEnum;
    }

    void XamlUserType::IsEnum(bool value)
    {
        _isEnum = value;
    }

    bool XamlUserType::IsBindable() const
    {
        return _isBindable;
    }

    void XamlUserType::IsBindable(bool value)
    {
        _isBindable = value;
    }

    bool XamlUserType::IsReturnTypeStub() const
    {
        return _isReturnTypeStub;
    }

    void XamlUserType::IsReturnTypeStub(bool value)
    {
        _isReturnTypeStub = value;
    }

    bool XamlUserType::IsLocalType() const
    {
        return _isLocalType;
    }

    void XamlUserType::IsLocalType(bool value)
    {
        _isLocalType = value;
    }

    IXamlMember XamlUserType::ContentProperty() const
    {
        return _provider->GetMemberByLongName(_contentPropertyName);
    }

    IXamlType XamlUserType::ItemType() const
    {
        return _provider->GetXamlTypeByName(_itemTypeName);
    }

    IXamlType XamlUserType::KeyType() const
    {
        return _provider->GetXamlTypeByName(_keyTypeName);
    }

    IXamlType XamlUserType::BoxedType() const
    {
        return _boxedType;
    }


    IXamlMember XamlUserType::GetMember(::winrt::hstring const& name) const
    {
        auto val = _memberNames.find(name.data());
        if (val != _memberNames.end())
        {
            return _provider->GetMemberByLongName(val->second);
        }
        return nullptr;
    }

    ::winrt::Windows::Foundation::IInspectable XamlUserType::ActivateInstance() const
    {
        return _activator();
    }

    void XamlUserType::AddToMap(::winrt::Windows::Foundation::IInspectable const& instance, ::winrt::Windows::Foundation::IInspectable const& key, ::winrt::Windows::Foundation::IInspectable const& item) const
    {
        _dictionaryAdd(instance, key, item);
    }

    void XamlUserType::AddToVector(::winrt::Windows::Foundation::IInspectable const& instance, ::winrt::Windows::Foundation::IInspectable const& item) const
    {
        _collectionAdd(instance, item);
    }

    void XamlUserType::RunInitializer() const
    {
        // The C++ runtime will have already run all the Static Initializers at start up.
    }

    ::winrt::Windows::Foundation::IInspectable XamlUserType::CreateFromString(::winrt::hstring const& input) const
    {
        // For boxed types, run the boxed type's CreateFromString method and boxing
        if (BoxedType() != nullptr)
        {
            return BoxedType().CreateFromString(input);
        }

        if (_createFromStringMethod)
        {
            return (*_createFromStringMethod)(input);
        }
        else
        {
            return _fromStringConverter(*this, input);
        }
    }

    void XamlUserType::ContentPropertyName(::winrt::hstring const& value) 
    { 
        _contentPropertyName = value; 
    }

    void XamlUserType::ItemTypeName(::winrt::hstring const& value)
    { 
        _itemTypeName = value; 
    }

    void XamlUserType::KeyTypeName(::winrt::hstring const& value)
    {
        _keyTypeName = value; 
    }
    void XamlUserType::SetBoxedType(IXamlType boxedType)
    {
        _boxedType = boxedType;
    }


    void XamlUserType::AddMemberName(::winrt::hstring const& shortName)
    {
        std::wstring longName = FullName().data();
        longName += L".";
        longName += shortName;
            _memberNames.insert_or_assign(shortName.data(), longName);
    }

    void XamlUserType::AddEnumValue(::winrt::hstring const& name, ::winrt::Windows::Foundation::IInspectable value)
    {
        _enumValues.insert_or_assign(name.data(), value);
    }

    uint32_t XamlUserType::CreateEnumUIntFromString(::winrt::hstring const& input) const
    {
        bool found = false;

        const std::wregex regularExpression(L"^\\s+|\\s*,\\s*|\\s+$");
        uint32_t val = 0;

        for (std::wcregex_token_iterator it{ input.begin(), input.end(), regularExpression, -1 }, end; it != end; ++it)
        {
            std::wcsub_match const& subMatch = *it;
            if (subMatch.length() == 0)
            {
                continue;
            }

            auto lookup{ subMatch.str() };

            try
            {
                auto entry = _enumValues.find(lookup);
                if (entry != _enumValues.end())
                {
                    val = winrt::unbox_value<int>(entry->second);
                }
                else
                {
                    val |= std::stoi(subMatch);
                }
                found = true;
            }
            catch (std::invalid_argument const&)
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return val;
        }
        throw ::winrt::hresult_invalid_argument {};
    }

 
    XamlMember::XamlMember(
        std::shared_ptr<XamlTypeInfoProvider> const& provider, 
        ::winrt::hstring const& name, 
        ::winrt::hstring const& typeName)
            : _provider(provider)
            , _name(name)
            , _typeName(typeName)
    {
    }

    void XamlMember::TargetTypeName(::winrt::hstring const& value)
    { 
        _targetTypeName = value; 
    }

    bool XamlMember::IsAttachable() const
    {
        return _isAttachable;
    }

    void XamlMember::IsAttachable(bool value)
    {
        _isAttachable = value;
    }

    bool XamlMember::IsDependencyProperty() const
    {
        return _isDependencyProperty;
    }

    void XamlMember::IsDependencyProperty(bool value)
    {
        _isDependencyProperty = value;
    }

    bool XamlMember::IsReadOnly() const
    {
        return _isReadOnly;
    }

    void XamlMember::IsReadOnly(bool value)
    {
        _isReadOnly = value;
    }

    ::winrt::hstring XamlMember::Name() const
    {
        return _name;
    }

    IXamlType XamlMember::Type() const
    {
        return _provider->GetXamlTypeByName(_typeName);
    }

    IXamlType XamlMember::TargetType() const
    {
        return _provider->GetXamlTypeByName(_targetTypeName);
    }

    ::winrt::Windows::Foundation::IInspectable XamlMember::GetValue(::winrt::Windows::Foundation::IInspectable const& instance) const
    {
        return _getter(instance);
    }

    void XamlMember::SetValue(::winrt::Windows::Foundation::IInspectable const& instance, ::winrt::Windows::Foundation::IInspectable const& value)
    {
        _setter(instance, value);
    }
}
