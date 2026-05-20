/* ===== 23e2808b0 ui.fishing_tab:c1121 ===== */
/* ghidra_name=FUN_23e2808b0 entry=23e2808b0 size=1522 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2808b0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined4 uVar11;
  longlong lVar12;
  code *pcVar13;
  undefined1 local_68 [16];
  longlong *local_58 [3];
  
  plVar9 = _DAT_23eeb0608;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  local_58[0] = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if (_DAT_23eeb0608 == (longlong *)0x0) {
LAB_23e280907:
    _DAT_23eeb0608 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb06a8,DAT_23eeb0600,0x20);
  }
  else {
    lVar12 = *_DAT_23eeb0608;
    if (1 < lVar12) {
      *_DAT_23eeb0608 = lVar12 + -1;
      goto LAB_23e280907;
    }
    if (_DAT_23eeb0608[2] != 0) {
      *_DAT_23eeb0608 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e280907;
    }
  }
  plVar5 = _DAT_23eeb0608;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb0608 + 9;
  lVar4 = *(longlong *)(lVar12 + 8);
  _DAT_23eeb0608[0xf] = lVar4;
  *(longlong **)(lVar12 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar12 = *(longlong *)(param_2 + 0xd8);
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  pcVar7 = _Py_NoneStruct_exref;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  if (lVar12 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar12 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar12 = DAT_23ed6cd40 + 0x30;
    }
    local_68._8_8_ =
         PyUnicode_FromFormat
                   ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                    ,lVar12);
    local_68._0_8_ = *(undefined8 *)PyExc_NameError_exref;
    *(longlong *)local_68._0_8_ = *(longlong *)local_68._0_8_ + 1;
    local_58[0] = (longlong *)0x0;
    if ((code *)local_68._0_8_ != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,local_68,local_68 + 8,local_58);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_68._8_8_);
    uVar11 = 0x37;
    plVar10 = DAT_23ed6a4f8;
    plVar9 = local_58[0];
  }
  else {
    pcVar13 = (code *)0x0;
    if (pcVar1 != _Py_NoneStruct_exref) {
      pcVar13 = pcVar1;
    }
    plVar9 = (longlong *)FUN_23e9543b0(param_1,DAT_23eeae828,lVar12,pcVar13);
    if (plVar9 != (longlong *)0x0) {
      *(undefined4 *)(plVar5 + 5) = 0x37;
      plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,DAT_23ed6cdb0,plVar3);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        cVar8 = FUN_23e8d9ac0(pcVar1,_DAT_23eeae840,plVar2);
        if (cVar8 != '\0') {
          lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar9 = *(longlong **)(lVar12 + 0x28);
          plVar5 = (longlong *)plVar9[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
          *(undefined4 *)(plVar9 + 8) = 0xffffffff;
          if (plVar5 != (longlong *)0x0) {
            plVar9[2] = 0;
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))();
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
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 != 0) {
            return pcVar7;
          }
          (**(code **)(plVar3[1] + 0x30))(plVar3);
          return pcVar7;
        }
        plVar9 = *(longlong **)(param_1 + 0x70);
        local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
        uVar11 = 0x38;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023e280b0b;
      }
    }
    local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uVar11 = 0x37;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = DAT_23ed6a4f8;
  }
joined_r0x00023e280b0b:
  DAT_23ed6a4f8 = plVar10;
  local_58[0] = plVar9;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar12 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar9 = plVar10;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)plVar9[3] != plVar5) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar12 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar10;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar9;
  FUN_23e8bba40(plVar5,&DAT_23ec5b378,pcVar1,plVar2,plVar3,*(undefined8 *)(param_2 + 0xd8));
  if (_DAT_23eeb0608 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0608 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar12 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
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
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,local_68._0_8_,local_68._8_8_,local_58[0]);
  return (code *)0x0;
}
