// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_lazy_dependencies.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025000 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_bases.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "google/protobuf/unittest_lazy_dependencies_custom_option.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto;
namespace protobuf_unittest {
namespace lazy_imports {
class ImportedMessage;
struct ImportedMessageDefaultTypeInternal;
extern ImportedMessageDefaultTypeInternal _ImportedMessage_default_instance_;
class MessageCustomOption;
struct MessageCustomOptionDefaultTypeInternal;
extern MessageCustomOptionDefaultTypeInternal _MessageCustomOption_default_instance_;
class MessageCustomOption2;
struct MessageCustomOption2DefaultTypeInternal;
extern MessageCustomOption2DefaultTypeInternal _MessageCustomOption2_default_instance_;
}  // namespace lazy_imports
}  // namespace protobuf_unittest
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace protobuf_unittest {
namespace lazy_imports {

// ===================================================================


// -------------------------------------------------------------------

class MessageCustomOption2 final : public ::google::protobuf::internal::ZeroFieldsBase
/* @@protoc_insertion_point(class_definition:protobuf_unittest.lazy_imports.MessageCustomOption2) */ {
 public:
  inline MessageCustomOption2() : MessageCustomOption2(nullptr) {}
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR MessageCustomOption2(
      ::google::protobuf::internal::ConstantInitialized);

  inline MessageCustomOption2(const MessageCustomOption2& from) : MessageCustomOption2(nullptr, from) {}
  MessageCustomOption2(MessageCustomOption2&& from) noexcept : MessageCustomOption2() {
    *this = ::std::move(from);
  }

  inline MessageCustomOption2& operator=(const MessageCustomOption2& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageCustomOption2& operator=(MessageCustomOption2&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageCustomOption2& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageCustomOption2* internal_default_instance() {
    return reinterpret_cast<const MessageCustomOption2*>(
        &_MessageCustomOption2_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 2;
  friend void swap(MessageCustomOption2& a, MessageCustomOption2& b) { a.Swap(&b); }
  inline void Swap(MessageCustomOption2* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageCustomOption2* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageCustomOption2* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::internal::ZeroFieldsBase::DefaultConstruct<MessageCustomOption2>(arena);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::CopyFrom;
  inline void CopyFrom(const MessageCustomOption2& from) {
    ::google::protobuf::internal::ZeroFieldsBase::CopyImpl(*this, from);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::MergeFrom;
  void MergeFrom(const MessageCustomOption2& from) {
    ::google::protobuf::internal::ZeroFieldsBase::MergeImpl(*this, from);
  }

  public:
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "protobuf_unittest.lazy_imports.MessageCustomOption2"; }

 protected:
  explicit MessageCustomOption2(::google::protobuf::Arena* arena);
  MessageCustomOption2(::google::protobuf::Arena* arena, const MessageCustomOption2& from);

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  // @@protoc_insertion_point(class_scope:protobuf_unittest.lazy_imports.MessageCustomOption2)
 private:
  class _Internal;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  friend struct ::TableStruct_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto;
};
// -------------------------------------------------------------------

class MessageCustomOption final : public ::google::protobuf::internal::ZeroFieldsBase
/* @@protoc_insertion_point(class_definition:protobuf_unittest.lazy_imports.MessageCustomOption) */ {
 public:
  inline MessageCustomOption() : MessageCustomOption(nullptr) {}
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR MessageCustomOption(
      ::google::protobuf::internal::ConstantInitialized);

  inline MessageCustomOption(const MessageCustomOption& from) : MessageCustomOption(nullptr, from) {}
  MessageCustomOption(MessageCustomOption&& from) noexcept : MessageCustomOption() {
    *this = ::std::move(from);
  }

  inline MessageCustomOption& operator=(const MessageCustomOption& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageCustomOption& operator=(MessageCustomOption&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageCustomOption& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageCustomOption* internal_default_instance() {
    return reinterpret_cast<const MessageCustomOption*>(
        &_MessageCustomOption_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(MessageCustomOption& a, MessageCustomOption& b) { a.Swap(&b); }
  inline void Swap(MessageCustomOption* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageCustomOption* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageCustomOption* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::internal::ZeroFieldsBase::DefaultConstruct<MessageCustomOption>(arena);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::CopyFrom;
  inline void CopyFrom(const MessageCustomOption& from) {
    ::google::protobuf::internal::ZeroFieldsBase::CopyImpl(*this, from);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::MergeFrom;
  void MergeFrom(const MessageCustomOption& from) {
    ::google::protobuf::internal::ZeroFieldsBase::MergeImpl(*this, from);
  }

  public:
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "protobuf_unittest.lazy_imports.MessageCustomOption"; }

 protected:
  explicit MessageCustomOption(::google::protobuf::Arena* arena);
  MessageCustomOption(::google::protobuf::Arena* arena, const MessageCustomOption& from);

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  // @@protoc_insertion_point(class_scope:protobuf_unittest.lazy_imports.MessageCustomOption)
 private:
  class _Internal;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  friend struct ::TableStruct_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto;
};
// -------------------------------------------------------------------

class ImportedMessage final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:protobuf_unittest.lazy_imports.ImportedMessage) */ {
 public:
  inline ImportedMessage() : ImportedMessage(nullptr) {}
  ~ImportedMessage() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR ImportedMessage(
      ::google::protobuf::internal::ConstantInitialized);

  inline ImportedMessage(const ImportedMessage& from) : ImportedMessage(nullptr, from) {}
  ImportedMessage(ImportedMessage&& from) noexcept : ImportedMessage() {
    *this = ::std::move(from);
  }

  inline ImportedMessage& operator=(const ImportedMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline ImportedMessage& operator=(ImportedMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ImportedMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const ImportedMessage* internal_default_instance() {
    return reinterpret_cast<const ImportedMessage*>(
        &_ImportedMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(ImportedMessage& a, ImportedMessage& b) { a.Swap(&b); }
  inline void Swap(ImportedMessage* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ImportedMessage* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ImportedMessage* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<ImportedMessage>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ImportedMessage& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const ImportedMessage& from) { ImportedMessage::MergeImpl(*this, from); }

  private:
  static void MergeImpl(::google::protobuf::Message& to_msg,
                        const ::google::protobuf::Message& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(ImportedMessage* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "protobuf_unittest.lazy_imports.ImportedMessage"; }

 protected:
  explicit ImportedMessage(::google::protobuf::Arena* arena);
  ImportedMessage(::google::protobuf::Arena* arena, const ImportedMessage& from);
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kLazyMessageFieldNumber = 1,
  };
  // .protobuf_unittest.lazy_imports.LazyMessage lazy_message = 1;
  bool has_lazy_message() const;
  void clear_lazy_message() ;
  const ::protobuf_unittest::lazy_imports::LazyMessage& lazy_message() const;
  PROTOBUF_NODISCARD ::protobuf_unittest::lazy_imports::LazyMessage* release_lazy_message();
  ::protobuf_unittest::lazy_imports::LazyMessage* mutable_lazy_message();
  void set_allocated_lazy_message(::protobuf_unittest::lazy_imports::LazyMessage* value);
  void unsafe_arena_set_allocated_lazy_message(::protobuf_unittest::lazy_imports::LazyMessage* value);
  ::protobuf_unittest::lazy_imports::LazyMessage* unsafe_arena_release_lazy_message();

  private:
  const ::protobuf_unittest::lazy_imports::LazyMessage& _internal_lazy_message() const;
  ::protobuf_unittest::lazy_imports::LazyMessage* _internal_mutable_lazy_message();

  public:
  // @@protoc_insertion_point(class_scope:protobuf_unittest.lazy_imports.ImportedMessage)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::protobuf_unittest::lazy_imports::LazyMessage* lazy_message_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ImportedMessage

// .protobuf_unittest.lazy_imports.LazyMessage lazy_message = 1;
inline bool ImportedMessage::has_lazy_message() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.lazy_message_ != nullptr);
  return value;
}
inline const ::protobuf_unittest::lazy_imports::LazyMessage& ImportedMessage::_internal_lazy_message() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::protobuf_unittest::lazy_imports::LazyMessage* p = _impl_.lazy_message_;
  return p != nullptr ? *p : reinterpret_cast<const ::protobuf_unittest::lazy_imports::LazyMessage&>(::protobuf_unittest::lazy_imports::_LazyMessage_default_instance_);
}
inline const ::protobuf_unittest::lazy_imports::LazyMessage& ImportedMessage::lazy_message() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf_unittest.lazy_imports.ImportedMessage.lazy_message)
  return _internal_lazy_message();
}
inline void ImportedMessage::unsafe_arena_set_allocated_lazy_message(::protobuf_unittest::lazy_imports::LazyMessage* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.lazy_message_);
  }
  _impl_.lazy_message_ = reinterpret_cast<::protobuf_unittest::lazy_imports::LazyMessage*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protobuf_unittest.lazy_imports.ImportedMessage.lazy_message)
}
inline ::protobuf_unittest::lazy_imports::LazyMessage* ImportedMessage::release_lazy_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::protobuf_unittest::lazy_imports::LazyMessage* released = _impl_.lazy_message_;
  _impl_.lazy_message_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::protobuf_unittest::lazy_imports::LazyMessage* ImportedMessage::unsafe_arena_release_lazy_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf_unittest.lazy_imports.ImportedMessage.lazy_message)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::protobuf_unittest::lazy_imports::LazyMessage* temp = _impl_.lazy_message_;
  _impl_.lazy_message_ = nullptr;
  return temp;
}
inline ::protobuf_unittest::lazy_imports::LazyMessage* ImportedMessage::_internal_mutable_lazy_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.lazy_message_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::protobuf_unittest::lazy_imports::LazyMessage>(GetArena());
    _impl_.lazy_message_ = reinterpret_cast<::protobuf_unittest::lazy_imports::LazyMessage*>(p);
  }
  return _impl_.lazy_message_;
}
inline ::protobuf_unittest::lazy_imports::LazyMessage* ImportedMessage::mutable_lazy_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::protobuf_unittest::lazy_imports::LazyMessage* _msg = _internal_mutable_lazy_message();
  // @@protoc_insertion_point(field_mutable:protobuf_unittest.lazy_imports.ImportedMessage.lazy_message)
  return _msg;
}
inline void ImportedMessage::set_allocated_lazy_message(::protobuf_unittest::lazy_imports::LazyMessage* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.lazy_message_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.lazy_message_ = reinterpret_cast<::protobuf_unittest::lazy_imports::LazyMessage*>(value);
  // @@protoc_insertion_point(field_set_allocated:protobuf_unittest.lazy_imports.ImportedMessage.lazy_message)
}

// -------------------------------------------------------------------

// MessageCustomOption

// -------------------------------------------------------------------

// MessageCustomOption2

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace lazy_imports
}  // namespace protobuf_unittest


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5flazy_5fdependencies_2eproto_2epb_2eh
