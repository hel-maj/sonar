/* ===== 23e2e2dc0 ui.hotkey_dialog:c469 ===== */
/* ghidra_name=FUN_23e2e2dc0 entry=23e2e2dc0 size=1496 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2e2dc0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  code *pcVar12;
  undefined4 uVar13;
  undefined1 local_68 [16];
  longlong *local_58 [3];
  
  plVar9 = _DAT_23eeb01b8;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_58[0] = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if (_DAT_23eeb01b8 != (longlong *)0x0) {
    lVar11 = *_DAT_23eeb01b8;
    if (lVar11 < 2) {
      if (_DAT_23eeb01b8[2] == 0) goto LAB_23e2e2e39;
      *_DAT_23eeb01b8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
    else {
      *_DAT_23eeb01b8 = lVar11 + -1;
    }
  }
  _DAT_23eeb01b8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb01b0,DAT_23eeb0268,0x18);
LAB_23e2e2e39:
  plVar4 = _DAT_23eeb01b8;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb01b8 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eeb01b8[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar6 = _DAT_23eead610;
  *(undefined4 *)(plVar4 + 8) = 0;
  *(undefined4 *)(plVar4 + 5) = 0xf0;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,uVar6);
  if (plVar9 == (longlong *)0x0) {
    local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_58[0] = *(longlong **)(param_1 + 0x70);
    uVar13 = 0xf0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    pcVar7 = _Py_NoneStruct_exref;
    lVar11 = *(longlong *)(*(longlong *)(param_2 + 0xd8) + 0x10);
    if (lVar11 == 0) {
      if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
         ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
        lVar11 = *(longlong *)(DAT_23ed6cd40 + 0x38);
      }
      else {
        lVar11 = DAT_23ed6cd40 + 0x30;
      }
      local_68._8_8_ =
           PyUnicode_FromFormat
                     ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                      ,lVar11);
      local_68._0_8_ = *(undefined8 *)PyExc_NameError_exref;
      *(longlong *)local_68._0_8_ = *(longlong *)local_68._0_8_ + 1;
      local_58[0] = (longlong *)0x0;
      if ((code *)local_68._0_8_ != _Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,local_68,local_68 + 8,local_58);
      }
      uVar13 = 0xf1;
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_68._8_8_);
    }
    else {
      pcVar12 = (code *)0x0;
      if (pcVar1 != _Py_NoneStruct_exref) {
        pcVar12 = pcVar1;
      }
      plVar9 = (longlong *)FUN_23e9543b0(param_1,DAT_23eead8e0,lVar11,pcVar12);
      if (plVar9 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0xf1;
        plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eead768,plVar2);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar10 != (longlong *)0x0) {
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar9 = *(longlong **)(lVar11 + 0x28);
          plVar4 = (longlong *)plVar9[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
          *(undefined4 *)(plVar9 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar9[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
          plVar9[0xf] = 0;
          *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
          if (*(longlong *)pcVar1 == 0) {
            (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar7;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar7;
        }
      }
      local_58[0] = *(longlong **)(param_1 + 0x70);
      local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
      uVar13 = 0xf1;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
  }
  plVar10 = local_58[0];
  plVar9 = DAT_23ed6a4f8;
  if (local_58[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar10 = plVar9;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)local_58[0][3] != plVar4) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    plVar10 = plVar9;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar10;
  FUN_23e8bba40(plVar4,&DAT_23ec5b343,pcVar1,plVar2,*(undefined8 *)(param_2 + 0xd8));
  if (_DAT_23eeb01b8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb01b8 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar11 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_68._0_8_,local_68._8_8_,local_58[0]);
  return (code *)0x0;
}
