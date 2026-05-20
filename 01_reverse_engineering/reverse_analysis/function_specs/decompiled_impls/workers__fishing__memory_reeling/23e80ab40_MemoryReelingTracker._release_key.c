/* ===== 23e80ab40 workers.fishing.memory_reeling:MemoryReelingTracker._release_key ===== */
/* ghidra_name=FUN_23e80ab40 entry=23e80ab40 size=2587 */

code * FUN_23e80ab40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  code *pcVar13;
  undefined4 uVar14;
  code *pcVar15;
  code *pcVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined1 local_78 [16];
  code *local_68 [5];
  
  plVar9 = DAT_23eede8f8;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eede8f8 == (longlong *)0x0) {
LAB_23e80ab7f:
    DAT_23eede8f8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede968,DAT_23eedd0f8,8);
  }
  else {
    lVar2 = *DAT_23eede8f8;
    if (1 < lVar2) {
      *DAT_23eede8f8 = lVar2 + -1;
      goto LAB_23e80ab7f;
    }
    if (DAT_23eede8f8[2] != 0) {
      *DAT_23eede8f8 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e80ab7f;
    }
  }
  plVar4 = DAT_23eede8f8;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eede8f8 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  DAT_23eede8f8[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar9;
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
  uVar17 = DAT_23eedd1b0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar17);
  if (plVar9 == (longlong *)0x0) {
    pcVar15 = *(code **)(param_1 + 0x70);
    plVar10 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar16 = _PyRuntime_exref;
joined_r0x00023e80b05f:
    _PyRuntime_exref = pcVar16;
    if (pcVar15 != (code *)0x0) {
      pcVar13 = pcVar15;
      if (*(longlong **)(pcVar15 + 0x18) == plVar4) goto LAB_23e80b110;
      uVar14 = 0xf3;
LAB_23e80b082:
      pcVar13 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar6 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar6;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar13 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar16 + 0x1f8);
      *(undefined4 *)(pcVar13 + 0x24) = uVar14;
      lVar2 = *(longlong *)(lVar2 + 0x10);
      *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
      lVar2 = *(longlong *)(lVar2 + 0x2e8);
      lVar3 = *(longlong *)(pcVar13 + -8);
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = pcVar13 + -0x10;
      *(longlong *)(pcVar13 + -0x10) = lVar2;
      *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *(longlong *)pcVar15;
      *(code **)(lVar2 + 8) = pcVar13 + -0x10;
      *(code **)(pcVar13 + 0x10) = pcVar15;
      if (lVar3 == 0) {
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
      }
      goto LAB_23e80b110;
    }
    uVar14 = 0xf3;
  }
  else {
    iVar8 = FUN_23a35f020(plVar9);
    lVar2 = *plVar9 + -1;
    if (iVar8 == -1) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar15 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar9 = lVar2;
      pcVar16 = _PyRuntime_exref;
      if (lVar2 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        pcVar16 = _PyRuntime_exref;
      }
      goto joined_r0x00023e80b05f;
    }
    *plVar9 = lVar2;
    pcVar15 = _Py_NoneStruct_exref;
    if (lVar2 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      pcVar15 = _Py_NoneStruct_exref;
    }
    _Py_NoneStruct_exref = pcVar15;
    if (iVar8 == 0) goto LAB_23e80ac55;
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd120);
    if (plVar9 == (longlong *)0x0) {
LAB_23e80ae40:
      pcVar15 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = *(undefined8 *)(param_1 + 0x60);
      uVar18 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e80ae59:
      plVar9 = *(longlong **)(param_1 + 0x138);
      local_78._8_8_ = uVar18;
      local_78._0_8_ = uVar17;
      if (plVar9 != (longlong *)0x0) {
        *plVar9 = *plVar9 + 1;
      }
      pcVar12 = DAT_23ed6a4f8;
      local_68[0] = pcVar15;
      if (pcVar15 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar15 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar15;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar12 + 0x18) = plVar4;
        *(longlong *)(pcVar12 + 0x10) = 0;
        pcVar16 = _PyRuntime_exref;
        *plVar4 = *plVar4 + 1;
        *(longlong *)(pcVar12 + 0x20) = 0xf5ffffffff;
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = *(longlong *)(pcVar12 + -8);
        puVar5 = *(undefined8 **)(lVar2 + 8);
        *puVar5 = pcVar12 + -0x10;
        *(longlong *)(pcVar12 + -0x10) = lVar2;
        *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
        *(code **)(lVar2 + 8) = pcVar12 + -0x10;
        if ((local_68[0] != (code *)0x0) &&
           (*(longlong *)local_68[0] = *(longlong *)local_68[0] + -1, *(longlong *)local_68[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_68[0] + 8) + 0x30))(local_68[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar16 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar16;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar12 + 0x18) = plVar4;
        pcVar16 = _PyRuntime_exref;
        *plVar4 = *plVar4 + 1;
        *(longlong *)(pcVar12 + 0x20) = 0xf5ffffffff;
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = *(longlong *)(pcVar12 + -8);
        puVar5 = *(undefined8 **)(lVar2 + 8);
        *puVar5 = pcVar12 + -0x10;
        *(longlong *)(pcVar12 + -0x10) = lVar2;
        *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
        *(code **)(lVar2 + 8) = pcVar12 + -0x10;
        *(code **)(pcVar12 + 0x10) = pcVar15;
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
        if ((local_68[0] != (code *)0x0) &&
           (*(longlong *)local_68[0] = *(longlong *)local_68[0] + -1, *(longlong *)local_68[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_68[0] + 8) + 0x30))();
        }
      }
      pcVar15 = _Py_NoneStruct_exref;
      local_68[0] = pcVar12;
      if (((code *)local_78._0_8_ != (code *)0x0) &&
         ((code *)local_78._0_8_ != _Py_NoneStruct_exref)) {
        FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
      }
      plVar10 = *(longlong **)(local_78._8_8_ + 0x28);
      if (local_68[0] == pcVar15) {
        pcVar12 = (code *)0x0;
      }
      else {
        pcVar12 = local_68[0];
        if (local_68[0] != (code *)0x0) {
          *(longlong *)local_68[0] = *(longlong *)local_68[0] + 1;
        }
      }
      *(code **)(local_78._8_8_ + 0x28) = pcVar12;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      plVar10 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = local_78._8_8_;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      *(longlong *)local_78._0_8_ = *(longlong *)local_78._0_8_ + -1;
      if (*(longlong *)local_78._0_8_ == 0) {
        (**(code **)(*(longlong *)(local_78._0_8_ + 8) + 0x30))();
      }
      if ((local_68[0] != (code *)0x0) &&
         (*(longlong *)local_68[0] = *(longlong *)local_68[0] + -1, *(longlong *)local_68[0] == 0))
      {
        (**(code **)(*(longlong *)(local_68[0] + 8) + 0x30))();
      }
      local_68[0] = (code *)0x0;
      local_78 = (undefined1  [16])0x0;
      iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      if (iVar8 != 0) {
        plVar10 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar9;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        goto LAB_23e80adb0;
      }
      pcVar12 = *(code **)(param_1 + 0x138);
      if ((pcVar12 == (code *)0x0) || (pcVar12 == pcVar15)) {
        plVar10 = *(longlong **)PyExc_RuntimeError_exref;
        pcVar12 = (code *)PyUnicode_FromString("No active exception to reraise");
        plVar11 = *(longlong **)(param_1 + 0x138);
        *plVar10 = *plVar10 + 1;
        *(longlong **)(param_1 + 0x138) = plVar9;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        uVar14 = 0xf4;
        goto LAB_23e80b273;
      }
      plVar10 = *(longlong **)(pcVar12 + 8);
      pcVar15 = *(code **)(pcVar12 + 0x28);
      *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
      *plVar10 = *plVar10 + 1;
      if (pcVar15 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar9;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 == 0) {
          (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
        }
        uVar14 = (undefined4)plVar4[5];
        goto LAB_23e80b273;
      }
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
      pcVar13 = pcVar15;
      if (plVar4 == *(longlong **)(pcVar15 + 0x18)) {
        *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar15 + 0x24);
        *(longlong **)(param_1 + 0x138) = plVar9;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 != 0) goto LAB_23e80b110;
LAB_23e80b1dd:
        (*(code *)plVar10[6])(pcVar12);
        if (plVar4 == *(longlong **)(pcVar15 + 0x18)) goto LAB_23e80b110;
      }
      else {
        *(longlong **)(param_1 + 0x138) = plVar9;
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 == 0) goto LAB_23e80b1dd;
      }
      uVar14 = (undefined4)plVar4[5];
      goto LAB_23e80b082;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eedd308);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23e80ae40;
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd1b0);
    if (plVar9 == (longlong *)0x0) {
      uVar17 = *(undefined8 *)(param_1 + 0x60);
      uVar18 = *(undefined8 *)(param_1 + 0x68);
      pcVar15 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e80ae59;
    }
    *(undefined4 *)(plVar4 + 5) = 0xf5;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar9);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e80ae40;
    *plVar11 = *plVar11 + -1;
    pcVar15 = _Py_NoneStruct_exref;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
LAB_23e80adb0:
    cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eedd1b0,pcVar15);
    if (cVar7 != '\0') {
LAB_23e80ac55:
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar9 = *(longlong **)(lVar2 + 0x28);
      plVar4 = (longlong *)plVar9[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
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
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
      plVar9[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcVar15;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcVar15;
    }
    pcVar15 = *(code **)(param_1 + 0x70);
    plVar10 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar16 = _PyRuntime_exref;
    if (pcVar15 != (code *)0x0) {
      pcVar13 = pcVar15;
      if (*(longlong **)(pcVar15 + 0x18) == plVar4) goto LAB_23e80b110;
      uVar14 = 0xf8;
      goto LAB_23e80b082;
    }
    uVar14 = 0xf8;
  }
LAB_23e80b273:
  pcVar13 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar15 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar15;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar13 + 0x10) = 0;
  *(longlong **)(pcVar13 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  lVar2 = *(longlong *)(pcVar16 + 0x1f8);
  *(undefined4 *)(pcVar13 + 0x24) = uVar14;
  lVar2 = *(longlong *)(lVar2 + 0x10);
  *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
  lVar2 = *(longlong *)(lVar2 + 0x2e8);
  lVar3 = *(longlong *)(pcVar13 + -8);
  puVar5 = *(undefined8 **)(lVar2 + 8);
  *puVar5 = pcVar13 + -0x10;
  *(longlong *)(pcVar13 + -0x10) = lVar2;
  *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
  *(code **)(lVar2 + 8) = pcVar13 + -0x10;
LAB_23e80b110:
  FUN_23e8bba40(plVar4,&DAT_23ec5e2bc,plVar1);
  if (DAT_23eede8f8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eede8f8 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
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
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar10,pcVar12,pcVar13);
  return (code *)0x0;
}
