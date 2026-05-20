/* ===== 23e719590 workers.fishing.fish_recognition:262 ===== */
/* ghidra_name=FUN_23e719590 entry=23e719590 size=5828 */

code * FUN_23e719590(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  undefined4 uVar16;
  longlong **unaff_R14;
  undefined8 uVar17;
  undefined8 local_90;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = DAT_23eedb058;
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23eedb058 == (longlong *)0x0) {
LAB_23e7195e4:
    DAT_23eedb058 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb050,DAT_23eedb148,0x18);
  }
  else {
    lVar11 = *DAT_23eedb058;
    if (1 < lVar11) {
      *DAT_23eedb058 = lVar11 + -1;
      goto LAB_23e7195e4;
    }
    if (DAT_23eedb058[2] != 0) {
      *DAT_23eedb058 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7195e4;
    }
  }
  plVar3 = DAT_23eedb058;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eedb058 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  DAT_23eedb058[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar9 = DAT_23eeda0d0;
  *(undefined4 *)(plVar3 + 8) = 0;
  *(undefined4 *)(plVar3 + 5) = 0x108;
  plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar9);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x108;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  iVar7 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  pcVar15 = _Py_NoneStruct_exref;
  if (iVar7 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x108;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  if (iVar7 == 0) {
    lVar11 = *(longlong *)(param_1 + 0x38);
    lVar2 = *(longlong *)(lVar11 + 8);
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    plVar8 = *(longlong **)(lVar2 + 0x28);
    plVar3 = (longlong *)plVar8[2];
    *(undefined8 *)(lVar11 + 8) = *(undefined8 *)(lVar2 + 0x30);
    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
    if (plVar3 != (longlong *)0x0) {
      plVar8[2] = 0;
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))();
      }
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8[0xf] = 0;
    goto LAB_23e719707;
  }
  uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar3 + 5) = 0x10b;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0d8);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x10b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar3 + 5) = 0x10c;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0e0);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x10c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar3 + 5) = 0x10d;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0e8);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x10d;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
  pcVar15 = DAT_23eeda0f0;
  lVar11 = *(longlong *)(param_1 + 0x10);
  plVar8 = *(longlong **)(lVar11 + 0xe20);
  if (plVar8 == (longlong *)0x0) {
    plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
  }
  else {
    lVar2 = plVar8[3];
    *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
    *(longlong *)(lVar11 + 0xe20) = lVar2;
    *plVar8 = 1;
  }
  pcVar5 = _PyRuntime_exref;
  plVar8[4] = 0;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar8[-1];
  puVar4 = *(undefined8 **)(lVar11 + 8);
  *puVar4 = plVar8 + -2;
  plVar8[-2] = lVar11;
  plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar11 + 8) = plVar8 + -2;
  uVar17 = DAT_23eed9ea0;
  *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
  plVar8[3] = (longlong)pcVar15;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar17);
  uVar17 = DAT_23ed6cd28;
  if (plVar10 != (longlong *)0x0) {
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      plVar12 = plVar10;
      if (plVar13 == (longlong *)0x0) goto LAB_23e71a881;
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
    }
    unaff_R14 = &local_88;
    uStack_80 = uVar17;
    local_88 = plVar10;
    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar11 != 0) {
      plVar8[4] = lVar11;
      pcVar15 = PyUnicode_Join_exref;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0x10e;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e71a4ef;
      }
      *(undefined4 *)(plVar3 + 5) = 0x10e;
      plVar8 = (longlong *)FUN_23e914090(param_1,uVar9,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar8 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0x10e;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = (longlong *)0x0;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e71a4ef;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      local_90 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar10 = DAT_23eeda0f8;
      lVar11 = *(longlong *)(param_1 + 0x10);
      plVar8 = *(longlong **)(lVar11 + 0xe50);
      if (plVar8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
      }
      else {
        lVar2 = plVar8[3];
        *(int *)(lVar11 + 0xed4) = *(int *)(lVar11 + 0xed4) + -1;
        *(longlong *)(lVar11 + 0xe50) = lVar2;
        *plVar8 = 1;
      }
      pcVar5 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar8 + 3) = (undefined1  [16])0x0;
      *(undefined1 (*) [16])(plVar8 + 5) = (undefined1  [16])0x0;
      *(undefined1 (*) [16])(plVar8 + 7) = (undefined1  [16])0x0;
      *(undefined1 (*) [16])(plVar8 + 9) = (undefined1  [16])0x0;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar8[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar8 + -2;
      plVar8[-2] = lVar11;
      plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar11 + 8) = plVar8 + -2;
      uVar9 = DAT_23eed9ea8;
      *plVar10 = *plVar10 + 1;
      plVar8[3] = (longlong)plVar10;
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar9);
      if (plVar12 == (longlong *)0x0) {
LAB_23e71a450:
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        uVar16 = 0x10f;
      }
      else {
        plVar10 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9ef0);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        uVar17 = DAT_23ed6cd28;
        if (plVar10 == (longlong *)0x0) goto LAB_23e71a450;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          plVar12 = plVar10;
          if (plVar13 == (longlong *)0x0) goto LAB_23e71a881;
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
        }
        uStack_80 = uVar17;
        local_88 = plVar10;
        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (lVar11 == 0) goto LAB_23e71a450;
        plVar8[4] = lVar11;
        plVar10 = DAT_23eed9f78;
        uVar9 = DAT_23eed9ea8;
        *DAT_23eed9f78 = *DAT_23eed9f78 + 1;
        plVar8[5] = (longlong)plVar10;
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar9);
        if (plVar12 == (longlong *)0x0) goto LAB_23e71a450;
        plVar10 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9f80);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        uVar17 = DAT_23ed6cd28;
        if (plVar10 == (longlong *)0x0) goto LAB_23e71a450;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          plVar12 = plVar10;
          if (plVar13 == (longlong *)0x0) goto LAB_23e71a881;
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
        }
        uStack_80 = uVar17;
        local_88 = plVar10;
        lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (lVar11 == 0) goto LAB_23e71a450;
        plVar8[6] = lVar11;
        plVar10 = DAT_23eeda100;
        uVar9 = DAT_23eed9ea8;
        *DAT_23eeda100 = *DAT_23eeda100 + 1;
        plVar8[7] = (longlong)plVar10;
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar9);
        if (plVar12 != (longlong *)0x0) {
          plVar10 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9f90);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar10 != (longlong *)0x0) {
            plVar12 = plVar10;
            uVar17 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e71a894;
            do {
              local_88 = plVar12;
              uStack_80 = uVar17;
              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (lVar11 == 0) break;
              plVar8[8] = lVar11;
              plVar10 = DAT_23eeda108;
              uVar9 = DAT_23eed9ea8;
              *DAT_23eeda108 = *DAT_23eeda108 + 1;
              plVar8[9] = (longlong)plVar10;
              plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar9);
              if (plVar12 == (longlong *)0x0) break;
              plVar10 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9fa0);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              uVar17 = DAT_23ed6cd28;
              if (plVar10 == (longlong *)0x0) break;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                plVar12 = plVar10;
                if (plVar13 != (longlong *)0x0) {
                  *plVar13 = *plVar13 + 1;
                  DAT_23ed6a4c0 = plVar13;
                  goto LAB_23e719ca1;
                }
              }
              else {
LAB_23e719ca1:
                uStack_80 = uVar17;
                local_88 = plVar10;
                lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (lVar11 == 0) break;
                plVar8[10] = lVar11;
                plVar10 = (longlong *)(*pcVar15)(DAT_23ed6cd28,plVar8);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar10 == (longlong *)0x0) {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  plVar12 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0x10f;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar10 = (longlong *)0x0;
                  plVar13 = DAT_23ed6a4f8;
                  goto joined_r0x00023e71a4ef;
                }
                *(undefined4 *)(plVar3 + 5) = 0x10f;
                plVar8 = (longlong *)FUN_23e914090(param_1,local_90,plVar10);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar8 == (longlong *)0x0) {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  plVar10 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0x10f;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = (longlong *)0x0;
                  plVar13 = DAT_23ed6a4f8;
                  goto joined_r0x00023e71a4ef;
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                local_90 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar10 = DAT_23eeda110;
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar8 = *(longlong **)(lVar11 + 0xe20);
                if (plVar8 == (longlong *)0x0) {
                  plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar2 = plVar8[3];
                  *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
                  *(longlong *)(lVar11 + 0xe20) = lVar2;
                  *plVar8 = 1;
                }
                pcVar5 = _PyRuntime_exref;
                plVar8[4] = 0;
                lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                lVar2 = plVar8[-1];
                puVar4 = *(undefined8 **)(lVar11 + 8);
                *puVar4 = plVar8 + -2;
                plVar8[-2] = lVar11;
                plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
                *(longlong **)(lVar11 + 8) = plVar8 + -2;
                uVar9 = DAT_23eed9eb0;
                *plVar10 = *plVar10 + 1;
                plVar8[3] = (longlong)plVar10;
                plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar9);
                if (plVar12 == (longlong *)0x0) goto LAB_23e71a8c6;
                plVar10 = (longlong *)FUN_23e8bd600(param_1,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                uVar17 = DAT_23ed6cd28;
                if (plVar10 == (longlong *)0x0) goto LAB_23e71a8c6;
                if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e719e4c;
                plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                plVar12 = plVar10;
                if (plVar13 != (longlong *)0x0) goto code_r0x00023e71a9b8;
              }
LAB_23e71a881:
              do {
                PyErr_PrintEx(0);
                Py_Exit(1);
LAB_23e71a894:
                plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              } while (plVar13 == (longlong *)0x0);
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            } while( true );
          }
        }
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        uVar16 = 0x110;
      }
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        plVar8 = local_68;
        plVar13 = DAT_23ed6a4f8;
        goto joined_r0x00023e71a4ef;
      }
      goto LAB_23e71a5f0;
    }
  }
  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_68 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    uVar16 = 0x10e;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    plVar8 = local_68;
    plVar13 = DAT_23ed6a4f8;
  }
  else {
    uVar16 = 0x10e;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar8 = local_68;
    plVar13 = DAT_23ed6a4f8;
  }
  goto joined_r0x00023e71a4ef;
code_r0x00023e71a9b8:
  *plVar13 = *plVar13 + 1;
  DAT_23ed6a4c0 = plVar13;
LAB_23e719e4c:
  uStack_80 = uVar17;
  local_88 = plVar10;
  lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R14);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (lVar11 != 0) {
    plVar8[4] = lVar11;
    plVar10 = (longlong *)(*pcVar15)(DAT_23ed6cd28,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar10 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x111;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *(undefined4 *)(plVar3 + 5) = 0x111;
    plVar8 = (longlong *)FUN_23e914090(param_1,local_90,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0x111;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x112;
    plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0e8);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0x112;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *(undefined4 *)(plVar3 + 5) = 0x114;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eeda118);
    if (plVar8 == (longlong *)0x0) {
LAB_23e71a9cb:
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar9 = *(undefined8 *)(param_1 + 0x60);
      uVar17 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e71a9e4:
      uVar16 = 0x114;
      plVar12 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_78._8_8_ = uVar17;
      local_78._0_8_ = uVar9;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    plVar13 = (longlong *)FUN_23a388310(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e71a9cb;
    plVar10 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if ((plVar10 == (longlong *)0x0) &&
       (plVar10 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2), plVar8 = local_68,
       plVar10 == (longlong *)0x0)) {
      uVar9 = local_78._0_8_;
      uVar17 = local_78._8_8_;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      goto LAB_23e71a9e4;
    }
    plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
    if (((plVar12 == (longlong *)0x0) &&
        (plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar12 == (longlong *)0x0)) ||
       (cVar6 = FUN_23a3884a0(param_1,local_78,plVar13), cVar6 == '\0')) {
      plVar8 = local_68;
      uVar9 = local_78._0_8_;
      uVar17 = local_78._8_8_;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      local_68 = (longlong *)0x0;
      local_78 = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e71a9e4;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      FUN_23a334bc0(plVar13);
    }
    if (*plVar10 == 0) {
      FUN_23a334bc0(plVar10);
    }
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x116;
    plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0d8);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x116;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0(plVar8);
    }
    iVar7 = FUN_23a35f020(plVar10);
    if (iVar7 == -1) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x117;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    if (iVar7 != 0) {
      uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar8 = DAT_23eeda120;
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
      *plVar8 = *plVar8 + 1;
      plVar14[3] = (longlong)plVar8;
      lVar11 = FUN_23e94f9d0(param_1,plVar10);
      if (lVar11 != 0) {
        plVar14[4] = lVar11;
        plVar8 = DAT_23eeda128;
        *DAT_23eeda128 = *DAT_23eeda128 + 1;
        plVar14[5] = (longlong)plVar8;
        lVar11 = FUN_23e94f9d0(param_1,plVar12);
        if (lVar11 != 0) {
          plVar14[6] = lVar11;
          plVar8 = DAT_23eeda130;
          *DAT_23eeda130 = *DAT_23eeda130 + 1;
          plVar14[7] = (longlong)plVar8;
          plVar8 = (longlong *)(*pcVar15)(DAT_23ed6cd28,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            FUN_23a334bc0();
          }
          if (plVar8 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x118;
            plVar13 = (longlong *)FUN_23e914090(param_1,uVar9,plVar8);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              FUN_23a334bc0();
            }
            if (plVar13 != (longlong *)0x0) {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0(plVar13);
              }
              goto LAB_23e71a159;
            }
          }
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar8 = *(longlong **)(param_1 + 0x70);
          uVar16 = 0x118;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e71a4ef;
        }
      }
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x118;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar14 = *plVar14 + -1;
      plVar8 = local_68;
      plVar13 = DAT_23ed6a4f8;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
        plVar8 = local_68;
        plVar13 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e71a4ef;
    }
    uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x11a;
    plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda138);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x11a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0(plVar8);
    }
LAB_23e71a159:
    uVar9 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x11b;
    plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar9,DAT_23eeda0e8);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x11b;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e71a4ef;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0(plVar8);
    }
    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
    pcVar15 = _Py_NoneStruct_exref;
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      FUN_23a334bc0(plVar10);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      *plVar1 = *plVar1 + -1;
      lVar11 = *plVar1;
      goto joined_r0x00023e71a1d1;
    }
LAB_23e719707:
    *plVar1 = *plVar1 + -1;
    lVar11 = *plVar1;
joined_r0x00023e71a1d1:
    if (lVar11 != 0) {
      return pcVar15;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return pcVar15;
  }
LAB_23e71a8c6:
  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_68 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    uVar16 = 0x111;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    plVar8 = local_68;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e71a4ef;
  }
  uVar16 = 0x111;
LAB_23e71a5f0:
  plVar12 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  plVar8 = local_68;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e71a4ef:
  DAT_23ed6a4f8 = plVar13;
  local_68 = plVar8;
  if (plVar8 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar11;
    plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar13 + -2;
    plVar14 = plVar13;
  }
  else {
    plVar14 = plVar8;
    if ((longlong *)plVar8[3] != plVar3) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar15 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar11 = *(longlong *)(pcVar15 + 0x1f8);
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar16;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar2 = plVar13[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar13 + -2;
      plVar13[-2] = lVar11;
      plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar8;
      *(longlong **)(lVar11 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar8;
      plVar14 = plVar13;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  local_68 = plVar14;
  FUN_23e8bba40(plVar3,&DAT_23ec5dead,plVar1,plVar10,plVar12);
  if (DAT_23eedb058 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eedb058 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar11 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar3 = local_68;
  uVar17 = local_78._8_8_;
  plVar8[0xf] = 0;
  local_68 = (longlong *)0x0;
  uVar9 = local_78._0_8_;
  local_78 = (undefined1  [16])0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar9,uVar17,plVar3);
  return (code *)0x0;
}
