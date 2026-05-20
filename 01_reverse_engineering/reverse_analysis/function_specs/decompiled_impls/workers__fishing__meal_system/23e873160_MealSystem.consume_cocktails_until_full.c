/* ===== 23e873160 workers.fishing.meal_system:409 ===== */
/* ghidra_name=FUN_23e873160 entry=23e873160 size=13684 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e873160(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  byte bVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  longlong *plVar17;
  longlong *plVar18;
  code *pcVar19;
  undefined4 uVar20;
  code *pcVar21;
  code *pcVar22;
  undefined8 uVar23;
  undefined8 in_stack_fffffffffffffef8;
  code *pcStack_d8;
  code *pcStack_d0;
  code *pcStack_c8;
  undefined1 *puStack_c0;
  code *pcStack_b8;
  longlong *plStack_b0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined1 auStack_78 [16];
  code *pcStack_68;
  
  plVar10 = _DAT_23eedec18;
  plVar1 = (longlong *)*param_3;
  pcStack_68 = (code *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eedec18 == (longlong *)0x0) {
LAB_23e8731bd:
    _DAT_23eedec18 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec10,DAT_23eed7940);
  }
  else {
    lVar11 = *_DAT_23eedec18;
    if (1 < lVar11) {
      *_DAT_23eedec18 = lVar11 + -1;
      goto LAB_23e8731bd;
    }
    if (_DAT_23eedec18[2] != 0) {
      *_DAT_23eedec18 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e8731bd;
    }
  }
  plVar3 = _DAT_23eedec18;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedec18 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eedec18[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  *(undefined4 *)(plVar3 + 5) = 0x19b;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uRam000000023eed75d0);
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_68 == (code *)0x0) goto LAB_23e874610;
    if (plVar3 != *(longlong **)(pcStack_68 + 0x18)) {
      pcVar22 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x19b;
      pcStack_d8 = (code *)0x0;
      pcStack_c8 = _PyRuntime_exref;
      pcVar16 = (code *)0x0;
      goto LAB_23e873f4a;
    }
LAB_23e8741e0:
    pcVar22 = (code *)0x0;
    pcVar21 = (code *)0x0;
    plStack_b0 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcStack_d8 = (code *)0x0;
    pcVar16 = (code *)0x0;
    pcVar15 = pcStack_68;
    goto LAB_23e873ff4;
  }
  iVar8 = FUN_23a35f020();
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  if (iVar8 == -1) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_68 != (code *)0x0) {
      if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
      pcVar22 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plStack_b0 = (longlong *)0x0;
      pcStack_d8 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      pcStack_c8 = _PyRuntime_exref;
      iVar8 = 0x19b;
      goto LAB_23e873f4a;
    }
LAB_23e874610:
    pcVar22 = (code *)0x0;
    pcVar21 = (code *)0x0;
    plStack_b0 = (longlong *)0x0;
    pcStack_d8 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    pcVar16 = (code *)0x0;
    pcStack_c8 = _PyRuntime_exref;
    iVar8 = 0x19b;
LAB_23e873e30:
    pcVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar19 = pcStack_68;
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar19 = (code *)0x0;
    }
    *(longlong *)(pcVar15 + 0x10) = 0;
    *(longlong **)(pcVar15 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(int *)(pcVar15 + 0x24) = iVar8;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = *(longlong *)(pcVar15 + -8);
    plVar13 = *(longlong **)(lVar11 + 8);
    *plVar13 = (longlong)(pcVar15 + -0x10);
    *(longlong *)(pcVar15 + -0x10) = lVar11;
    *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar13;
    *(code **)(lVar11 + 8) = pcVar15 + -0x10;
    if ((pcVar19 != (code *)0x0) &&
       (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
      (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
    }
  }
  else {
    if (iVar8 == 0) {
LAB_23e873297:
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcStack_d8 = (code *)0x0;
      pcStack_d0 = _Py_NoneStruct_exref;
      lVar11 = *(longlong *)_Py_NoneStruct_exref + 1;
      pcVar19 = (code *)0x0;
      goto LAB_23e8732bb;
    }
    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x19e;
    plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed75d8);
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_68 != (code *)0x0) {
        if (*(longlong **)(pcStack_68 + 0x18) == plVar3) goto LAB_23e8741e0;
        pcVar22 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plStack_b0 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 0x19e;
        pcStack_d8 = (code *)0x0;
        pcStack_c8 = _PyRuntime_exref;
        pcVar16 = (code *)0x0;
        goto LAB_23e873f4a;
      }
      pcVar22 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x19e;
      pcStack_d8 = (code *)0x0;
      pcStack_c8 = _PyRuntime_exref;
      pcVar16 = (code *)0x0;
      pcStack_68 = (code *)0x0;
      goto LAB_23e873e30;
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x19f;
    plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed75e0);
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_68 == (code *)0x0) {
        pcVar22 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plStack_b0 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 0x19f;
        pcStack_d8 = (code *)0x0;
        pcStack_c8 = _PyRuntime_exref;
        pcVar16 = (code *)0x0;
        pcStack_68 = (code *)0x0;
        goto LAB_23e873e30;
      }
      if (*(longlong **)(pcStack_68 + 0x18) == plVar3) goto LAB_23e8741e0;
      pcVar22 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x19f;
      pcStack_d8 = (code *)0x0;
      pcStack_c8 = _PyRuntime_exref;
      pcVar16 = (code *)0x0;
    }
    else {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar3 + 5) = 0x1a0;
      plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed75e8);
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
        plVar13 = plRam000000023eed75f0;
        lVar11 = *(longlong *)(param_1 + 0x10);
        plVar10 = *(longlong **)(lVar11 + 0xe20);
        if (plVar10 == (longlong *)0x0) {
          plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar2 = plVar10[3];
          *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
          *(longlong *)(lVar11 + 0xe20) = lVar2;
          *plVar10 = 1;
        }
        pcStack_c8 = _PyRuntime_exref;
        plVar10[4] = 0;
        lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c8 + 0x1f8) + 0x10) + 0x2e8);
        lVar2 = plVar10[-1];
        puVar4 = *(undefined8 **)(lVar11 + 8);
        *puVar4 = plVar10 + -2;
        plVar10[-2] = lVar11;
        plVar10[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar11 + 8) = plVar10 + -2;
        uVar23 = uRam000000023eed72b0;
        *plVar13 = *plVar13 + 1;
        plVar10[3] = (longlong)plVar13;
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,uVar23);
        uVar23 = DAT_23ed6cd28;
        if (plVar13 == (longlong *)0x0) {
LAB_23e874220:
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
            if (pcStack_68 != (code *)0x0) {
              plVar10 = *(longlong **)(pcStack_68 + 0x18);
              goto joined_r0x00023e874367;
            }
          }
          else if (pcStack_68 != (code *)0x0) {
            plVar10 = *(longlong **)(pcStack_68 + 0x18);
joined_r0x00023e874367:
            if (plVar3 == plVar10) goto LAB_23e8741e0;
            pcVar22 = (code *)0x0;
            pcVar21 = (code *)0x0;
            plStack_b0 = (longlong *)0x0;
            pcStack_d8 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar16 = (code *)0x0;
            iVar8 = 0x1a1;
            goto LAB_23e873f4a;
          }
        }
        else {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            plVar14 = plVar13;
            if (plVar17 == (longlong *)0x0) goto LAB_23e874733;
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
          }
          puStack_c0 = auStack_98;
          auStack_98._8_8_ = uVar23;
          auStack_98._0_8_ = plVar13;
          lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_c0);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if (lVar11 == 0) goto LAB_23e874220;
          plVar10[4] = lVar11;
          pcStack_b8 = PyUnicode_Join_exref;
          plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
          }
          if (plVar13 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x1a1;
            plVar10 = (longlong *)FUN_23e914090(param_1,uVar12,plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            if (plVar10 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              pcStack_68 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcStack_68 == (code *)0x0) goto LAB_23e874680;
              if (*(longlong **)(pcStack_68 + 0x18) == plVar3) goto LAB_23e8741e0;
              pcVar22 = (code *)0x0;
              pcVar21 = (code *)0x0;
              plStack_b0 = (longlong *)0x0;
              pcStack_d8 = (code *)0x0;
              pcVar16 = (code *)0x0;
              iVar8 = 0x1a1;
              plVar10 = (longlong *)0x0;
              goto LAB_23e873f4a;
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
            plVar13 = plRam000000023eed75f8;
            lVar11 = *(longlong *)(param_1 + 0x10);
            plVar10 = *(longlong **)(lVar11 + 0xe50);
            if (plVar10 == (longlong *)0x0) {
              plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
            }
            else {
              lVar2 = plVar10[3];
              *(int *)(lVar11 + 0xed4) = *(int *)(lVar11 + 0xed4) + -1;
              *(longlong *)(lVar11 + 0xe50) = lVar2;
              *plVar10 = 1;
            }
            *(undefined1 (*) [16])(plVar10 + 3) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar10 + 5) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar10 + 7) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar10 + 9) = (undefined1  [16])0x0;
            lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c8 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar10[-1];
            puVar4 = *(undefined8 **)(lVar11 + 8);
            *puVar4 = plVar10 + -2;
            plVar10[-2] = lVar11;
            plVar10[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar11 + 8) = plVar10 + -2;
            uVar23 = uRam000000023eed72b8;
            *plVar13 = *plVar13 + 1;
            plVar10[3] = (longlong)plVar13;
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar23);
            if (plVar14 == (longlong *)0x0) {
LAB_23e873db0:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              pcStack_68 = *(code **)(param_1 + 0x70);
              iVar8 = 0x1a2;
            }
            else {
              plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar14,uRam000000023eed7318);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              uVar23 = DAT_23ed6cd28;
              if (plVar13 == (longlong *)0x0) goto LAB_23e873db0;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                plVar14 = plVar13;
                if (plVar17 == (longlong *)0x0) goto LAB_23e874733;
                *plVar17 = *plVar17 + 1;
                DAT_23ed6a4c0 = plVar17;
              }
              auStack_98._8_8_ = uVar23;
              auStack_98._0_8_ = plVar13;
              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_c0);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              if (lVar11 == 0) goto LAB_23e873db0;
              plVar10[4] = lVar11;
              plVar13 = plRam000000023eed7600;
              *plRam000000023eed7600 = *plRam000000023eed7600 + 1;
              plVar10[5] = (longlong)plVar13;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72b8);
              if (plVar14 == (longlong *)0x0) goto LAB_23e873db0;
              plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar14,uRam000000023eed7410);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              uVar23 = DAT_23ed6cd28;
              if (plVar13 == (longlong *)0x0) goto LAB_23e873db0;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                plVar14 = plVar13;
                if (plVar17 == (longlong *)0x0) goto LAB_23e874733;
                *plVar17 = *plVar17 + 1;
                DAT_23ed6a4c0 = plVar17;
              }
              auStack_98._8_8_ = uVar23;
              auStack_98._0_8_ = plVar13;
              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_c0);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              if (lVar11 == 0) goto LAB_23e873db0;
              plVar10[6] = lVar11;
              plVar13 = plRam000000023eed7608;
              *plRam000000023eed7608 = *plRam000000023eed7608 + 1;
              plVar10[7] = (longlong)plVar13;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72b8);
              if (plVar14 != (longlong *)0x0) {
                plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar14,uRam000000023eed7420);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
                if (plVar13 != (longlong *)0x0) {
                  plVar14 = plVar13;
                  uVar23 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e874746;
                  while( true ) {
                    auStack_98._8_8_ = uVar23;
                    auStack_98._0_8_ = plVar14;
                    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_c0);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))();
                    }
                    if (lVar11 == 0) goto LAB_23e874480;
                    plVar10[8] = lVar11;
                    plVar13 = plRam000000023eed7610;
                    *plRam000000023eed7610 = *plRam000000023eed7610 + 1;
                    plVar10[9] = (longlong)plVar13;
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72b8);
                    if (plVar14 == (longlong *)0x0) goto LAB_23e874480;
                    plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar14,uRam000000023eed7418);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    uVar23 = DAT_23ed6cd28;
                    uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e874480;
                    if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e873a15;
                    plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
                    plVar14 = plVar13;
                    if (plVar17 != (longlong *)0x0) break;
LAB_23e874733:
                    do {
                      PyErr_PrintEx(0,0);
                      Py_Exit(1);
LAB_23e874746:
                      plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    } while (plVar17 == (longlong *)0x0);
                    *plVar17 = *plVar17 + 1;
                    DAT_23ed6a4c0 = plVar17;
                  }
                  *plVar17 = *plVar17 + 1;
                  DAT_23ed6a4c0 = plVar17;
LAB_23e873a15:
                  auStack_98._8_8_ = uVar23;
                  auStack_98._0_8_ = plVar13;
                  lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_c0);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if (lVar11 != 0) {
                    plVar10[10] = lVar11;
                    plVar13 = (longlong *)(*pcStack_b8)(DAT_23ed6cd28,plVar10);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                    if (plVar13 == (longlong *)0x0) {
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (pcStack_68 == (code *)0x0) {
LAB_23e875b9d:
                        pcVar22 = (code *)0x0;
                        pcVar21 = (code *)0x0;
                        pcStack_d8 = (code *)0x0;
                        plStack_b0 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        pcVar16 = (code *)0x0;
                        iVar8 = 0x1a2;
                        goto LAB_23e873e30;
                      }
                      if (*(longlong **)(pcStack_68 + 0x18) == plVar3) goto LAB_23e8741e0;
                      pcVar22 = (code *)0x0;
                      pcVar21 = (code *)0x0;
                      pcStack_d8 = (code *)0x0;
                      plStack_b0 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      iVar8 = 0x1a2;
                      pcVar16 = (code *)0x0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x1a2;
                      plVar10 = (longlong *)FUN_23e914090(param_1,uVar12,plVar13);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))();
                      }
                      if (plVar10 == (longlong *)0x0) {
                        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        pcStack_68 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcStack_68 == (code *)0x0) goto LAB_23e875b9d;
                        if (*(longlong **)(pcStack_68 + 0x18) == plVar3) goto LAB_23e8741e0;
                        pcVar22 = (code *)0x0;
                        pcVar21 = (code *)0x0;
                        pcStack_d8 = (code *)0x0;
                        plStack_b0 = (longlong *)0x0;
                        pcVar16 = (code *)0x0;
                        iVar8 = 0x1a2;
                        plVar10 = (longlong *)0x0;
                      }
                      else {
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                        *(undefined4 *)(plVar3 + 5) = 0x1a4;
                        plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12);
                        if (plVar10 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          pcStack_68 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (pcStack_68 == (code *)0x0) {
                            pcVar22 = (code *)0x0;
                            pcVar21 = (code *)0x0;
                            pcStack_d8 = (code *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            iVar8 = 0x1a4;
                            plVar10 = (longlong *)0x0;
                            pcVar16 = (code *)0x0;
                            pcStack_68 = (code *)0x0;
                            goto LAB_23e873e30;
                          }
                          if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
                          pcVar22 = (code *)0x0;
                          pcStack_d8 = (code *)0x0;
                          pcVar21 = (code *)0x0;
                          plStack_b0 = (longlong *)0x0;
                          pcVar16 = (code *)0x0;
                          iVar8 = 0x1a4;
                          plVar10 = (longlong *)0x0;
                        }
                        else {
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                          *(undefined4 *)(plVar3 + 5) = 0x1a5;
                          plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed7620);
                          if (plVar10 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            pcStack_68 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (pcStack_68 == (code *)0x0) {
                              pcVar22 = (code *)0x0;
                              pcVar21 = (code *)0x0;
                              pcStack_d8 = (code *)0x0;
                              plStack_b0 = (longlong *)0x0;
                              iVar8 = 0x1a5;
                              plVar10 = (longlong *)0x0;
                              pcVar16 = (code *)0x0;
                              pcStack_68 = (code *)0x0;
                              goto LAB_23e873e30;
                            }
                            if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
                            pcVar22 = (code *)0x0;
                            pcStack_d8 = (code *)0x0;
                            pcVar21 = (code *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            pcVar16 = (code *)0x0;
                            iVar8 = 0x1a5;
                            plVar10 = (longlong *)0x0;
                          }
                          else {
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                            *(undefined4 *)(plVar3 + 5) = 0x1a6;
                            plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed7628)
                            ;
                            if (plVar10 == (longlong *)0x0) {
                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                              pcStack_68 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (pcStack_68 == (code *)0x0) {
                                pcVar22 = (code *)0x0;
                                pcVar21 = (code *)0x0;
                                pcStack_d8 = (code *)0x0;
                                plStack_b0 = (longlong *)0x0;
                                iVar8 = 0x1a6;
                                plVar10 = (longlong *)0x0;
                                pcVar16 = (code *)0x0;
                                pcStack_68 = (code *)0x0;
                                goto LAB_23e873e30;
                              }
                              if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
                              pcVar22 = (code *)0x0;
                              pcVar21 = (code *)0x0;
                              pcStack_d8 = (code *)0x0;
                              plStack_b0 = (longlong *)0x0;
                              pcVar16 = (code *)0x0;
                              iVar8 = 0x1a6;
                              plVar10 = (longlong *)0x0;
                            }
                            else {
                              *plVar10 = *plVar10 + -1;
                              if (*plVar10 == 0) {
                                (**(code **)(plVar10[1] + 0x30))(plVar10);
                              }
                              uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                              *(undefined4 *)(plVar3 + 5) = 0x1a7;
                              plVar10 = (longlong *)
                                        FUN_23e94bb80(param_1,uVar12,uRam000000023eed7630);
                              if (plVar10 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                pcStack_68 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (pcStack_68 == (code *)0x0) {
                                  pcVar22 = (code *)0x0;
                                  pcVar21 = (code *)0x0;
                                  pcStack_d8 = (code *)0x0;
                                  plStack_b0 = (longlong *)0x0;
                                  iVar8 = 0x1a7;
                                  plVar10 = (longlong *)0x0;
                                  pcVar16 = (code *)0x0;
                                  pcStack_68 = (code *)0x0;
                                  goto LAB_23e873e30;
                                }
                                if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
                                pcVar22 = (code *)0x0;
                                pcStack_d8 = (code *)0x0;
                                pcVar21 = (code *)0x0;
                                plStack_b0 = (longlong *)0x0;
                                pcVar16 = (code *)0x0;
                                iVar8 = 0x1a7;
                                plVar10 = (longlong *)0x0;
                              }
                              else {
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                }
                                uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                *(undefined4 *)(plVar3 + 5) = 0x1a8;
                                plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12);
                                if (plVar10 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (pcStack_68 == (code *)0x0) {
                                    pcVar22 = (code *)0x0;
                                    pcVar21 = (code *)0x0;
                                    pcStack_d8 = (code *)0x0;
                                    iVar8 = 0x1a8;
                                    plStack_b0 = (longlong *)0x0;
                                    plVar10 = (longlong *)0x0;
                                    pcVar16 = (code *)0x0;
                                    pcStack_68 = (code *)0x0;
                                    goto LAB_23e873e30;
                                  }
                                  if (plVar3 == *(longlong **)(pcStack_68 + 0x18))
                                  goto LAB_23e8741e0;
                                  pcVar22 = (code *)0x0;
                                  pcStack_d8 = (code *)0x0;
                                  pcVar21 = (code *)0x0;
                                  plStack_b0 = (longlong *)0x0;
                                  pcVar16 = (code *)0x0;
                                  iVar8 = 0x1a8;
                                  plVar10 = (longlong *)0x0;
                                }
                                else {
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                                  }
                                  *(undefined4 *)(plVar3 + 5) = 0x1ac;
                                  plVar10 = (longlong *)
                                            FUN_23e91bfe0(param_1,plVar1,uRam000000023eed7640);
                                  if (plVar10 != (longlong *)0x0) {
                                    iVar8 = FUN_23a35f020();
                                    lVar11 = *plVar10 + -1;
                                    if (iVar8 == -1) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar10 = lVar11;
                                      if (lVar11 == 0) {
                                        FUN_23a334bc0(plVar10);
                                      }
                                      goto LAB_23e874864;
                                    }
                                    *plVar10 = lVar11;
                                    if (lVar11 == 0) {
                                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                                    }
                                    if (iVar8 != 0) {
                                      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1ad;
                                      plVar10 = (longlong *)
                                                FUN_23e94bb80(param_1,uVar12,uRam000000023eed75d8);
                                      if (plVar10 == (longlong *)0x0) {
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        pcVar22 = (code *)0x0;
                                        pcVar21 = (code *)0x0;
                                        plVar10 = (longlong *)0x0;
                                        uVar20 = 0x1ad;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        pcStack_d8 = (code *)0x0;
                                        pcStack_d0 = _Py_NoneStruct_exref;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pcVar16 = (code *)0x0;
                                        plStack_b0 = (longlong *)0x0;
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      }
                                      else {
                                        *plVar10 = *plVar10 + -1;
                                        if (*plVar10 == 0) {
                                          FUN_23a334bc0(plVar10);
                                        }
                                        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                        *(undefined4 *)(plVar3 + 5) = 0x1ae;
                                        plVar10 = (longlong *)
                                                  FUN_23e94bb80(param_1,uVar12,uRam000000023eed7648)
                                        ;
                                        if (plVar10 == (longlong *)0x0) {
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          pcVar22 = (code *)0x0;
                                          pcVar21 = (code *)0x0;
                                          plVar10 = (longlong *)0x0;
                                          uVar20 = 0x1ae;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcStack_d8 = (code *)0x0;
                                          pcStack_d0 = _Py_NoneStruct_exref;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar16 = (code *)0x0;
                                          plStack_b0 = (longlong *)0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        }
                                        else {
                                          *plVar10 = *plVar10 + -1;
                                          if (*plVar10 == 0) {
                                            FUN_23a334bc0(plVar10);
                                          }
                                          uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                          *(undefined4 *)(plVar3 + 5) = 0x1af;
                                          plVar10 = (longlong *)
                                                    FUN_23e94bb80(param_1,uVar12,
                                                                  uRam000000023eed75e8);
                                          if (plVar10 != (longlong *)0x0) {
                                            *plVar10 = *plVar10 + -1;
                                            if (*plVar10 == 0) {
                                              FUN_23a334bc0(plVar10);
                                            }
                                            goto LAB_23e873297;
                                          }
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          pcVar21 = (code *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          pcVar22 = (code *)0x0;
                                          plVar10 = (longlong *)0x0;
                                          uVar20 = 0x1af;
                                          pcStack_d8 = (code *)0x0;
                                          pcStack_d0 = _Py_NoneStruct_exref;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar16 = (code *)0x0;
                                          plStack_b0 = (longlong *)0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        }
                                      }
                                      goto LAB_23e87488b;
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1b3;
                                    plVar10 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed7650);
                                    if (plVar10 == (longlong *)0x0) {
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      pcVar22 = (code *)0x0;
                                      pcVar21 = (code *)0x0;
                                      plVar10 = (longlong *)0x0;
                                      uVar20 = 0x1b3;
                                      pcStack_d8 = (code *)0x0;
                                      plStack_b0 = (longlong *)0x0;
                                      pcStack_d0 = _Py_NoneStruct_exref;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      pcVar16 = (code *)0x0;
                                      goto LAB_23e87488b;
                                    }
                                    *plVar10 = *plVar10 + -1;
                                    if (*plVar10 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed72a8);
                                    if (plVar10 == (longlong *)0x0) {
LAB_23e875603:
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1b6;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      goto LAB_23e874869;
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x1b6;
                                    pcVar16 = (code *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed72a8);
                                    *plVar10 = *plVar10 + -1;
                                    if (*plVar10 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    pcVar19 = _Py_NoneStruct_exref;
                                    uVar12 = DAT_23eed7550;
                                    if (pcVar16 == (code *)0x0) goto LAB_23e875603;
                                    pcStack_d0 = _Py_NoneStruct_exref;
                                    if (pcVar16 == _Py_NoneStruct_exref) {
                                      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1b8;
                                      plVar10 = (longlong *)FUN_23e94bb80(param_1,uVar12);
                                      if (plVar10 != (longlong *)0x0) {
                                        *plVar10 = *plVar10 + -1;
                                        if (*plVar10 == 0) {
                                          FUN_23a334bc0(plVar10);
                                        }
                                        plVar13 = (longlong *)0x0;
                                        plVar10 = (longlong *)0x0;
                                        pcStack_d8 = (code *)0x0;
                                        lVar11 = *(longlong *)pcVar19 + 1;
LAB_23e8732bb:
                                        *(longlong *)pcStack_d0 = lVar11;
                                        lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                        plVar3 = *(longlong **)(lVar11 + 0x28);
                                        plVar14 = (longlong *)plVar3[2];
                                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                             *(undefined8 *)(lVar11 + 0x30);
                                        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                                        if (plVar14 != (longlong *)0x0) {
                                          plVar3[2] = 0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))();
                                          }
                                        }
                                        *plVar3 = *plVar3 + -1;
                                        if (*plVar3 == 0) {
                                          (**(code **)(plVar3[1] + 0x30))(plVar3);
                                        }
                                        plVar3[0xf] = 0;
                                        pcVar22 = (code *)0x0;
                                        pcVar21 = (code *)0x0;
                                        pcVar16 = pcVar19;
                                        goto LAB_23e873314;
                                      }
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      pcVar22 = (code *)0x0;
                                      pcVar21 = (code *)0x0;
                                      plStack_b0 = (longlong *)0x0;
                                      uVar20 = 0x1b8;
                                      pcStack_d8 = (code *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plVar10 = (longlong *)0x0;
                                      goto LAB_23e87488b;
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x1bb;
                                    auStack_98._8_8_ = uVar12;
                                    auStack_98._0_8_ = pcVar16;
                                    plVar10 = (longlong *)
                                              FUN_23e954670(param_1,plVar1,DAT_23eed74e8,puStack_c0)
                                    ;
                                    if (plVar10 == (longlong *)0x0) {
LAB_23e875997:
                                      pcStack_d8 = *(code **)(param_1 + 0x70);
                                      uVar12 = *(undefined8 *)(param_1 + 0x60);
                                      uVar23 = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
LAB_23e8759b3:
                                      uVar20 = 0x1bb;
                                      pcVar22 = (code *)0x0;
                                      pcVar21 = (code *)0x0;
                                      plStack_b0 = (longlong *)0x0;
                                      plVar10 = (longlong *)0x0;
                                      pcStack_68 = pcStack_d8;
                                      pcStack_d8 = (code *)0x0;
                                      auStack_78._0_8_ = uVar12;
                                      auStack_78._8_8_ = uVar23;
                                      goto LAB_23e87488b;
                                    }
                                    plVar13 = (longlong *)FUN_23a388310(plVar10);
                                    *plVar10 = *plVar10 + -1;
                                    if (*plVar10 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    if (plVar13 == (longlong *)0x0) goto LAB_23e875997;
                                    uVar12 = CONCAT44(uVar20,4);
                                    plVar10 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar13,0,uVar12);
                                    if (plVar10 == (longlong *)0x0) {
                                      plVar17 = (longlong *)0x0;
                                      plVar14 = (longlong *)0x0;
                                      plStack_b0 = (longlong *)0x0;
LAB_23e875a5e:
                                      uVar12 = auStack_78._0_8_;
                                      uVar23 = auStack_78._8_8_;
                                      auStack_78 = (undefined1  [16])0x0;
                                      pcStack_d8 = pcStack_68;
                                      pcStack_68 = (code *)0x0;
                                      *plVar13 = *plVar13 + -1;
                                      if (*plVar13 == 0) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      pcStack_68 = (code *)0x0;
                                      auStack_78 = (undefined1  [16])0x0;
                                      if ((plVar10 != (longlong *)0x0) &&
                                         (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                                        FUN_23a334bc0(plVar10);
                                      }
                                      if ((plVar14 != (longlong *)0x0) &&
                                         (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      if ((plVar17 != (longlong *)0x0) &&
                                         (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                      if ((plStack_b0 != (longlong *)0x0) &&
                                         (lVar11 = *plStack_b0, *plStack_b0 = lVar11 + -1,
                                         lVar11 + -1 == 0)) {
                                        FUN_23a334bc0();
                                      }
                                      goto LAB_23e8759b3;
                                    }
                                    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),4);
                                    plVar14 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar13,1,uVar12);
                                    if (plVar14 == (longlong *)0x0) {
                                      plVar17 = (longlong *)0x0;
                                      plStack_b0 = (longlong *)0x0;
                                      goto LAB_23e875a5e;
                                    }
                                    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),4);
                                    plVar17 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar13,2,uVar12);
                                    if (plVar17 == (longlong *)0x0) {
                                      plStack_b0 = (longlong *)0x0;
                                      goto LAB_23e875a5e;
                                    }
                                    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),4);
                                    plStack_b0 = (longlong *)
                                                 FUN_23a3c1d30(param_1,auStack_78,plVar13,3,uVar12);
                                    uVar20 = (undefined4)((ulonglong)uVar12 >> 0x20);
                                    if ((plStack_b0 == (longlong *)0x0) ||
                                       (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar13,4),
                                       cVar7 == '\0')) goto LAB_23e875a5e;
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    if (*plVar10 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    *plVar17 = *plVar17 + 1;
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    *plStack_b0 = *plStack_b0 + 1;
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    lVar11 = *plStack_b0;
                                    *plStack_b0 = lVar11 + -1;
                                    if (lVar11 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    auStack_98._8_8_ = uRam000000023eed75a0;
                                    *(undefined4 *)(plVar3 + 5) = 0x1bc;
                                    plVar13 = (longlong *)
                                              FUN_23e954670(param_1,plVar1,DAT_23eed74e8,puStack_c0)
                                    ;
                                    if (plVar13 == (longlong *)0x0) {
LAB_23e876668:
                                      pcStack_b8 = *(code **)(param_1 + 0x70);
                                      uVar12 = *(undefined8 *)(param_1 + 0x60);
                                      uVar23 = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e87661b:
                                      pcVar22 = (code *)0x0;
                                      pcStack_d8 = (code *)0x0;
                                      uVar20 = 0x1bc;
                                      pcVar21 = (code *)0x0;
                                      pcStack_68 = pcStack_b8;
                                      auStack_78._0_8_ = uVar12;
                                      auStack_78._8_8_ = uVar23;
                                      goto LAB_23e87488b;
                                    }
                                    plVar14 = (longlong *)FUN_23a388310(plVar13);
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    if (plVar14 == (longlong *)0x0) goto LAB_23e876668;
                                    pcStack_d8 = (code *)FUN_23a3c1d30(param_1,auStack_78,plVar14,0,
                                                                       CONCAT44(uVar20,4));
                                    if (pcStack_d8 == (code *)0x0) {
                                      plVar13 = (longlong *)0x0;
                                      plVar18 = (longlong *)0x0;
                                      plVar17 = (longlong *)0x0;
LAB_23e87656d:
                                      uVar12 = auStack_78._0_8_;
                                      uVar23 = auStack_78._8_8_;
                                      auStack_78 = (undefined1  [16])0x0;
                                      pcStack_b8 = pcStack_68;
                                      pcStack_68 = (code *)0x0;
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      pcStack_68 = (code *)0x0;
                                      auStack_78 = (undefined1  [16])0x0;
                                      if ((pcStack_d8 != (code *)0x0) &&
                                         (lVar11 = *(longlong *)pcStack_d8,
                                         *(longlong *)pcStack_d8 = lVar11 + -1, lVar11 + -1 == 0)) {
                                        FUN_23a334bc0();
                                      }
                                      if ((plVar17 != (longlong *)0x0) &&
                                         (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                      if ((plVar18 != (longlong *)0x0) &&
                                         (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                                        FUN_23a334bc0(plVar18);
                                      }
                                      if ((plVar13 != (longlong *)0x0) &&
                                         (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      goto LAB_23e87661b;
                                    }
                                    plVar17 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar14,1,4);
                                    if (plVar17 == (longlong *)0x0) {
                                      plVar13 = (longlong *)0x0;
                                      plVar18 = (longlong *)0x0;
                                      goto LAB_23e87656d;
                                    }
                                    plVar18 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar14,2,4);
                                    if (plVar18 == (longlong *)0x0) {
                                      plVar13 = (longlong *)0x0;
                                      goto LAB_23e87656d;
                                    }
                                    plVar13 = (longlong *)
                                              FUN_23a3c1d30(param_1,auStack_78,plVar14,3,4);
                                    if ((plVar13 == (longlong *)0x0) ||
                                       (cVar7 = FUN_23a3884a0(param_1,auStack_78), cVar7 == '\0'))
                                    goto LAB_23e87656d;
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    if (*(longlong *)pcStack_d8 == 0) {
                                      FUN_23a334bc0(pcStack_d8);
                                    }
                                    *plVar17 = *plVar17 + 1;
                                    lVar11 = *plStack_b0;
                                    *plStack_b0 = lVar11 + -1;
                                    if (lVar11 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    *plVar18 = *plVar18 + 1;
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    *plVar18 = *plVar18 + -1;
                                    if (*plVar18 == 0) {
                                      FUN_23a334bc0(plVar18);
                                    }
                                    *plVar13 = *plVar13 + 1;
                                    *plVar18 = *plVar18 + -1;
                                    if (*plVar18 == 0) {
                                      FUN_23a334bc0(plVar18);
                                    }
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    uVar9 = FUN_23a35f020(plVar10);
                                    plStack_b0 = plVar13;
                                    if ((uVar9 == 0xffffffff) ||
                                       ((uVar9 == 0 &&
                                        (uVar9 = FUN_23a35f020(pcStack_d8), uVar9 == 0xffffffff))))
                                    {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      pcVar22 = (code *)0x0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar20 = 0x1be;
                                      pcVar21 = (code *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    if (((uVar9 ^ 1) & 1) != 0) {
                                      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1bf;
                                      plVar14 = (longlong *)FUN_23e94bb80(param_1,uVar12);
                                      if (plVar14 == (longlong *)0x0) {
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        pcVar22 = (code *)0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar20 = 0x1bf;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pcVar21 = (code *)0x0;
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      }
                                      else {
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                        *(undefined4 *)(plVar3 + 5) = 0x1c0;
                                        plVar14 = (longlong *)
                                                  FUN_23e94bb80(param_1,uVar12,uRam000000023eed7658)
                                        ;
                                        if (plVar14 == (longlong *)0x0) {
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          pcVar22 = (code *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar20 = 0x1c0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar21 = (code *)0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        }
                                        else {
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                          *(undefined4 *)(plVar3 + 5) = 0x1c1;
                                          plVar14 = (longlong *)
                                                    FUN_23e94bb80(param_1,uVar12,
                                                                  uRam000000023eed75e8);
                                          if (plVar14 != (longlong *)0x0) {
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            lVar11 = *(longlong *)pcVar19 + 1;
                                            pcVar19 = pcVar16;
                                            goto LAB_23e8732bb;
                                          }
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          pcVar22 = (code *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar20 = 0x1c1;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar21 = (code *)0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        }
                                      }
                                      goto LAB_23e87488b;
                                    }
                                    *(longlong *)_Py_FalseStruct_exref =
                                         *(longlong *)_Py_FalseStruct_exref + 1;
                                    iVar8 = FUN_23a35f020(plVar10);
                                    pcVar21 = _Py_FalseStruct_exref;
                                    if (iVar8 == -1) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      pcVar22 = (code *)0x0;
                                      uVar20 = 0x1c6;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    pcVar22 = _Py_FalseStruct_exref;
                                    pcVar19 = _Py_FalseStruct_exref;
                                    if (iVar8 != 0) {
                                      *(undefined4 *)(plVar3 + 5) = 0x1c7;
                                      pcVar19 = (code *)FUN_23e91bfe0(param_1,plVar1,
                                                                      uRam000000023eed7660);
                                      pcVar21 = _Py_FalseStruct_exref;
                                      if (pcVar19 == (code *)0x0) {
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        pcVar22 = (code *)0x0;
                                        uVar20 = 0x1c7;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        goto LAB_23e87488b;
                                      }
                                      *(longlong *)_Py_FalseStruct_exref =
                                           *(longlong *)_Py_FalseStruct_exref + -1;
                                      pcVar22 = pcVar21;
                                      if (*(longlong *)pcVar21 == 0) {
                                        FUN_23a334bc0(pcVar21);
                                        pcVar22 = _Py_FalseStruct_exref;
                                      }
                                    }
                                    pcVar21 = pcVar19;
                                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                                    iVar8 = FUN_23a35f020(pcStack_d8);
                                    pcVar22 = _Py_FalseStruct_exref;
                                    if (iVar8 == -1) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1cb;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    pcVar19 = _Py_FalseStruct_exref;
                                    if (iVar8 != 0) {
                                      *(undefined4 *)(plVar3 + 5) = 0x1cc;
                                      pcVar19 = (code *)FUN_23e91bfe0(param_1,plVar1,
                                                                      uRam000000023eed7668);
                                      pcVar22 = _Py_FalseStruct_exref;
                                      if (pcVar19 == (code *)0x0) {
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        uVar20 = 0x1cc;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        goto LAB_23e87488b;
                                      }
                                      *(longlong *)_Py_FalseStruct_exref =
                                           *(longlong *)_Py_FalseStruct_exref + -1;
                                      if (*(longlong *)pcVar22 == 0) {
                                        FUN_23a334bc0(pcVar22);
                                      }
                                    }
                                    pcVar22 = pcVar19;
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1cf;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed75d8);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1cf;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1d0;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed7670);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1d0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1d1;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed75e8);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1d1;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    plVar14 = plRam000000023eed7678;
                                    plVar17 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                    *plVar14 = *plVar14 + 1;
                                    plVar17[3] = (longlong)plVar14;
                                    iVar8 = FUN_23a35f020(pcVar21);
                                    if (iVar8 == -1) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
LAB_23e87638d:
                                      uVar20 = 0x1d2;
                                      goto LAB_23e87488b;
                                    }
                                    plVar14 = plRam000000023eed7688;
                                    if (iVar8 != 0) {
                                      plVar14 = plRam000000023eed7680;
                                    }
                                    *plVar14 = *plVar14 + 1;
                                    plVar17[4] = (longlong)plVar14;
                                    plVar14 = (longlong *)(*pcStack_b8)(DAT_23ed6cd28);
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    if (plVar14 == (longlong *)0x0) {
LAB_23e876365:
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      goto LAB_23e87638d;
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x1d2;
                                    plVar17 = (longlong *)FUN_23e914090(param_1,uVar12);
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    if (plVar17 == (longlong *)0x0) goto LAB_23e876365;
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    FUN_23a3a0d40(DAT_23ed6cf28);
                                    plVar14 = plRam000000023eed7690;
                                    plVar17 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                    *plVar14 = *plVar14 + 1;
                                    plVar17[3] = (longlong)plVar14;
                                    iVar8 = FUN_23a35f020(pcVar22);
                                    if (iVar8 == -1) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
LAB_23e876324:
                                      uVar20 = 0x1d3;
                                      goto LAB_23e87488b;
                                    }
                                    plVar14 = plRam000000023eed7688;
                                    if (iVar8 != 0) {
                                      plVar14 = plRam000000023eed7680;
                                    }
                                    *plVar14 = *plVar14 + 1;
                                    plVar17[4] = (longlong)plVar14;
                                    plVar14 = (longlong *)(*pcStack_b8)(DAT_23ed6cd28);
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    if (plVar14 == (longlong *)0x0) {
LAB_23e8762fd:
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      goto LAB_23e876324;
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x1d3;
                                    plVar17 = (longlong *)FUN_23e914090(param_1);
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    if (plVar17 == (longlong *)0x0) goto LAB_23e8762fd;
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    iVar8 = FUN_23a35f020(pcVar21);
                                    if (iVar8 == -1) {
LAB_23e8762cc:
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1d5;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    if (iVar8 != 0) {
                                      iVar8 = FUN_23a35f020(pcVar22);
                                      if (iVar8 != -1) {
                                        if (iVar8 != 1) goto LAB_23e876074;
                                        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                        *(undefined4 *)(plVar3 + 5) = 0x1d6;
                                        plVar14 = (longlong *)
                                                  FUN_23e94bb80(param_1,uVar12,uRam000000023eed7698)
                                        ;
                                        if (plVar14 == (longlong *)0x0) {
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          uVar20 = 0x1d6;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          goto LAB_23e87488b;
                                        }
                                        goto LAB_23e8760d8;
                                      }
                                      goto LAB_23e8762cc;
                                    }
LAB_23e876074:
                                    iVar8 = FUN_23a35f020(plVar10);
                                    if (iVar8 == -1) {
LAB_23e876215:
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1d7;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    bVar5 = (byte)iVar8;
                                    if (iVar8 == 0) {
                                      iVar8 = FUN_23a35f020(pcStack_d8);
                                      if (iVar8 == -1) goto LAB_23e876215;
                                      bVar5 = (byte)iVar8;
                                    }
                                    if (((bVar5 ^ 1) & 1) == 0) {
                                      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1da;
                                      plVar14 = (longlong *)
                                                FUN_23e94bb80(param_1,uVar12,uRam000000023eed76a8);
                                      if (plVar14 != (longlong *)0x0) goto LAB_23e8760d8;
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1da;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1d8;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed76a0);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1d8;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
LAB_23e8760d8:
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1dc;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed75e8);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      uVar20 = 0x1dc;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      goto LAB_23e87488b;
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
LAB_23e874c32:
                                    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                    plVar3 = *(longlong **)(lVar11 + 0x28);
                                    plVar14 = (longlong *)plVar3[2];
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                         *(undefined8 *)(lVar11 + 0x30);
                                    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                                    if (plVar14 != (longlong *)0x0) {
                                      plVar3[2] = 0;
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))();
                                      }
                                    }
                                    *plVar3 = *plVar3 + -1;
                                    if (*plVar3 == 0) {
                                      (**(code **)(plVar3[1] + 0x30))(plVar3);
                                    }
                                    plVar3[0xf] = 0;
                                    *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
LAB_23e873314:
                                    if ((pcVar16 != (code *)0x0) &&
                                       (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1,
                                       *(longlong *)pcVar16 == 0)) {
                                      (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
                                    }
                                    if ((plVar10 != (longlong *)0x0) &&
                                       (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                                    }
                                    if ((plVar13 != (longlong *)0x0) &&
                                       (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    if ((pcStack_d8 != (code *)0x0) &&
                                       (lVar11 = *(longlong *)pcStack_d8,
                                       *(longlong *)pcStack_d8 = lVar11 + -1, lVar11 + -1 == 0)) {
                                      (**(code **)(*(longlong *)((longlong)pcStack_d8 + 8) + 0x30))
                                                (pcStack_d8);
                                    }
                                    if ((pcVar21 != (code *)0x0) &&
                                       (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1,
                                       *(longlong *)pcVar21 == 0)) {
                                      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
                                    }
                                    if ((pcVar22 != (code *)0x0) &&
                                       (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1,
                                       *(longlong *)pcVar22 == 0)) {
                                      (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
                                    }
                                    *plVar1 = *plVar1 + -1;
                                    if (*plVar1 != 0) {
                                      return pcStack_d0;
                                    }
                                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                                    return pcStack_d0;
                                  }
                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e874864:
                                  uVar20 = 0x1ac;
LAB_23e874869:
                                  pcVar22 = (code *)0x0;
                                  pcVar21 = (code *)0x0;
                                  pcStack_d8 = (code *)0x0;
                                  plStack_b0 = (longlong *)0x0;
                                  plVar10 = (longlong *)0x0;
                                  pcVar16 = (code *)0x0;
                                  pcStack_d0 = _Py_NoneStruct_exref;
LAB_23e87488b:
                                  pcVar19 = pcStack_68;
                                  auStack_98._8_8_ = auStack_78._8_8_;
                                  auStack_98._0_8_ = auStack_78._0_8_;
                                  pcStack_68 = (code *)0x0;
                                  auStack_78 = (undefined1  [16])0x0;
                                  apcStack_88[0] = pcVar19;
                                  plVar13 = *(longlong **)(param_1 + 0x138);
                                  if (plVar13 != (longlong *)0x0) {
                                    *plVar13 = *plVar13 + 1;
                                  }
                                  pcVar15 = DAT_23ed6a4f8;
                                  if (pcVar19 == (code *)0x0) {
                                    if (DAT_23ed6a4f8 == (code *)0x0) {
                                      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                    }
                                    else {
                                      pcVar19 = *(code **)DAT_23ed6a4f8;
                                      *(undefined8 *)DAT_23ed6a4f8 = 1;
                                      DAT_23ed6a4f8 = pcVar19;
                                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                    }
                                    *(longlong *)(pcVar15 + 0x10) = 0;
                                    *(longlong **)(pcVar15 + 0x18) = plVar3;
                                    *plVar3 = *plVar3 + 1;
                                    *(undefined4 *)(pcVar15 + 0x24) = uVar20;
                                    lVar11 = *(longlong *)(pcStack_c8 + 0x1f8);
                                    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
                                    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
                                    lVar2 = *(longlong *)(pcVar15 + -8);
                                    plVar14 = *(longlong **)(lVar11 + 8);
                                    *plVar14 = (longlong)(pcVar15 + -0x10);
                                    *(longlong *)(pcVar15 + -0x10) = lVar11;
                                    *(ulonglong *)(pcVar15 + -8) =
                                         (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar14;
                                    *(code **)(lVar11 + 8) = pcVar15 + -0x10;
                                    if ((apcStack_88[0] != (code *)0x0) &&
                                       (*(longlong *)apcStack_88[0] =
                                             *(longlong *)apcStack_88[0] + -1,
                                       *(longlong *)apcStack_88[0] == 0)) {
                                      FUN_23a334bc0(apcStack_88[0]);
                                    }
                                  }
                                  else {
                                    if (DAT_23ed6a4f8 == (code *)0x0) {
                                      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                    }
                                    else {
                                      pcVar6 = *(code **)DAT_23ed6a4f8;
                                      *(undefined8 *)DAT_23ed6a4f8 = 1;
                                      DAT_23ed6a4f8 = pcVar6;
                                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                    }
                                    *(longlong **)(pcVar15 + 0x18) = plVar3;
                                    *plVar3 = *plVar3 + 1;
                                    *(undefined4 *)(pcVar15 + 0x24) = uVar20;
                                    lVar11 = *(longlong *)(pcStack_c8 + 0x1f8);
                                    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
                                    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
                                    plVar14 = *(longlong **)(lVar11 + 8);
                                    *plVar14 = (longlong)(pcVar15 + -0x10);
                                    *(longlong *)(pcVar15 + -0x10) = lVar11;
                                    *(ulonglong *)(pcVar15 + -8) =
                                         (ulonglong)plVar14 |
                                         (ulonglong)((uint)*(longlong *)(pcVar15 + -8) & 3);
                                    *(code **)(lVar11 + 8) = pcVar15 + -0x10;
                                    *(code **)(pcVar15 + 0x10) = pcVar19;
                                    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                                    if ((apcStack_88[0] != (code *)0x0) &&
                                       (*(longlong *)apcStack_88[0] =
                                             *(longlong *)apcStack_88[0] + -1,
                                       *(longlong *)apcStack_88[0] == 0)) {
                                      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))
                                                (apcStack_88[0]);
                                    }
                                  }
                                  apcStack_88[0] = pcVar15;
                                  if (((code *)auStack_98._0_8_ != pcStack_d0) &&
                                     ((code *)auStack_98._0_8_ != (code *)0x0)) {
                                    FUN_23e91b1b0(param_1,puStack_c0,auStack_98 + 8,apcStack_88);
                                  }
                                  plVar14 = *(longlong **)(auStack_98._8_8_ + 0x28);
                                  if (apcStack_88[0] == pcStack_d0) {
                                    pcVar19 = (code *)0x0;
                                  }
                                  else {
                                    pcVar19 = apcStack_88[0];
                                    if (apcStack_88[0] != (code *)0x0) {
                                      *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
                                    }
                                  }
                                  *(code **)(auStack_98._8_8_ + 0x28) = pcVar19;
                                  if ((plVar14 != (longlong *)0x0) &&
                                     (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                                    (**(code **)(plVar14[1] + 0x30))();
                                  }
                                  plVar14 = *(longlong **)(param_1 + 0x138);
                                  *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                                  if ((plVar14 != (longlong *)0x0) &&
                                     (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                                    (**(code **)(plVar14[1] + 0x30))();
                                  }
                                  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1
                                  ;
                                  if (*(longlong *)auStack_98._0_8_ == 0) {
                                    (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                                  }
                                  if ((apcStack_88[0] != (code *)0x0) &&
                                     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1
                                     , *(longlong *)apcStack_88[0] == 0)) {
                                    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
                                  }
                                  apcStack_88[0] = (code *)0x0;
                                  auStack_98 = (undefined1  [16])0x0;
                                  iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                                 (*(longlong *)(param_1 + 0x138) + 8
                                                                 ),
                                                        *(undefined8 *)PyExc_KeyboardInterrupt_exref
                                                       );
                                  if (iVar8 == 0) {
                                    pcVar19 = *(code **)(param_1 + 0x138);
                                    auStack_78._8_8_ = pcVar19;
                                    if ((pcVar19 == pcStack_d0) || (pcVar19 == (code *)0x0)) {
                                      plVar14 = *(longlong **)PyExc_RuntimeError_exref;
                                      pcVar19 = (code *)PyUnicode_FromString
                                                                  ("No active exception to reraise")
                                      ;
                                      iVar8 = 0x1aa;
                                      *plVar14 = *plVar14 + 1;
                                    }
                                    else {
                                      plVar14 = *(longlong **)(pcVar19 + 8);
                                      pcVar15 = *(code **)(pcVar19 + 0x28);
                                      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                                      *plVar14 = *plVar14 + 1;
                                      iVar8 = 0;
                                      if (pcVar15 != (code *)0x0) {
                                        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                                        if (*(longlong **)(pcVar15 + 0x18) == plVar3) {
                                          *(undefined4 *)(plVar3 + 5) =
                                               *(undefined4 *)(pcVar15 + 0x24);
                                        }
                                        goto LAB_23e8753aa;
                                      }
                                    }
                                    pcVar15 = (code *)0x0;
                                  }
                                  else {
                                    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x1df;
                                    plVar14 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar12,uRam000000023eed76b0);
                                    if (plVar14 == (longlong *)0x0) {
                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                      pcVar19 = *(code **)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      pcVar15 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      iVar8 = 0x1df;
                                    }
                                    else {
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      }
                                      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1e0;
                                      plVar14 = (longlong *)FUN_23e94bb80(param_1,uVar12);
                                      if (plVar14 == (longlong *)0x0) {
                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                        pcVar19 = *(code **)(param_1 + 0x68);
                                        pcVar15 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        iVar8 = 0x1e0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                      }
                                      else {
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                                        }
                                        uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                                        *(undefined4 *)(plVar3 + 5) = 0x1e1;
                                        plVar14 = (longlong *)
                                                  FUN_23e94bb80(param_1,uVar12,uRam000000023eed75e8)
                                        ;
                                        if (plVar14 != (longlong *)0x0) {
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))();
                                          }
                                          plVar3 = *(longlong **)(param_1 + 0x138);
                                          *(longlong **)(param_1 + 0x138) = plVar13;
                                          plVar13 = plStack_b0;
                                          if ((plVar3 != (longlong *)0x0) &&
                                             (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                                            (**(code **)(plVar3[1] + 0x30))();
                                          }
                                          goto LAB_23e874c32;
                                        }
                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                        pcVar19 = *(code **)(param_1 + 0x68);
                                        pcVar15 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        iVar8 = 0x1e1;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                      }
                                    }
                                  }
LAB_23e8753aa:
                                  plVar17 = *(longlong **)(param_1 + 0x138);
                                  pcStack_68 = (code *)0x0;
                                  auStack_78 = (undefined1  [16])0x0;
                                  *(longlong **)(param_1 + 0x138) = plVar13;
                                  if ((plVar17 != (longlong *)0x0) &&
                                     (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                                    (**(code **)(plVar17[1] + 0x30))();
                                  }
                                  auStack_78._8_8_ = pcVar19;
                                  auStack_78._0_8_ = plVar14;
                                  if (pcVar15 == (code *)0x0) {
                                    pcStack_68 = (code *)0x0;
                                    if (iVar8 == 0) {
                                      iVar8 = (int)plVar3[5];
                                    }
                                    goto LAB_23e873e30;
                                  }
                                  if (*(longlong **)(pcVar15 + 0x18) == plVar3) goto LAB_23e873ff4;
                                  pcStack_68 = pcVar15;
                                  if (iVar8 == 0) {
                                    iVar8 = (int)plVar3[5];
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    goto LAB_23e873f4a;
                  }
                }
              }
LAB_23e874480:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              pcStack_68 = *(code **)(param_1 + 0x70);
              iVar8 = 0x1a3;
            }
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))();
            }
            if (pcStack_68 == (code *)0x0) {
              pcVar22 = (code *)0x0;
              pcVar21 = (code *)0x0;
              plStack_b0 = (longlong *)0x0;
              pcStack_d8 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar16 = (code *)0x0;
              pcStack_68 = (code *)0x0;
              goto LAB_23e873e30;
            }
            if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
            pcVar22 = (code *)0x0;
            pcVar21 = (code *)0x0;
            plStack_b0 = (longlong *)0x0;
            pcStack_d8 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar16 = (code *)0x0;
            goto LAB_23e873f4a;
          }
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcStack_68 != (code *)0x0) {
            if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
            pcVar22 = (code *)0x0;
            pcVar21 = (code *)0x0;
            plStack_b0 = (longlong *)0x0;
            pcStack_d8 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            iVar8 = 0x1a1;
            pcVar16 = (code *)0x0;
            goto LAB_23e873f4a;
          }
        }
LAB_23e874680:
        pcVar22 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plStack_b0 = (longlong *)0x0;
        pcStack_d8 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar16 = (code *)0x0;
        iVar8 = 0x1a1;
        goto LAB_23e873e30;
      }
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_68 == (code *)0x0) {
        pcStack_c8 = _PyRuntime_exref;
        pcVar22 = (code *)0x0;
        pcVar21 = (code *)0x0;
        plStack_b0 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 0x1a0;
        pcStack_d8 = (code *)0x0;
        pcVar16 = (code *)0x0;
        pcStack_68 = (code *)0x0;
        goto LAB_23e873e30;
      }
      if (plVar3 == *(longlong **)(pcStack_68 + 0x18)) goto LAB_23e8741e0;
      pcStack_c8 = _PyRuntime_exref;
      pcVar22 = (code *)0x0;
      pcVar21 = (code *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x1a0;
      pcStack_d8 = (code *)0x0;
      pcVar16 = (code *)0x0;
    }
LAB_23e873f4a:
    pcVar19 = pcStack_68;
    pcVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar6 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar15 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(int *)(pcVar15 + 0x24) = iVar8;
    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar2 = *(longlong *)(pcVar15 + -8);
    plVar13 = *(longlong **)(lVar11 + 8);
    *plVar13 = (longlong)(pcVar15 + -0x10);
    *(longlong *)(pcVar15 + -0x10) = lVar11;
    *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar13;
    *(code **)(lVar11 + 8) = pcVar15 + -0x10;
    *(code **)(pcVar15 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    if ((pcStack_68 != (code *)0x0) &&
       (*(longlong *)pcStack_68 = *(longlong *)pcStack_68 + -1, *(longlong *)pcStack_68 == 0)) {
      (**(code **)(*(longlong *)(pcStack_68 + 8) + 0x30))(pcStack_68);
    }
  }
LAB_23e873ff4:
  pcStack_68 = pcVar15;
  FUN_23e8bba40(plVar3,"ooooooo",plVar1,pcVar16,plVar10,plStack_b0,pcStack_d8,pcVar21,pcVar22);
  if (_DAT_23eedec18 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedec18 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar13 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar19 = pcStack_68;
  plVar3[0xf] = 0;
  uVar12 = auStack_78._0_8_;
  uVar23 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  pcStack_68 = (code *)0x0;
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plStack_b0 != (longlong *)0x0) && (*plStack_b0 = *plStack_b0 + -1, *plStack_b0 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((pcStack_d8 != (code *)0x0) &&
     (lVar11 = *(longlong *)pcStack_d8, *(longlong *)pcStack_d8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcStack_d8 + 8) + 0x30))(pcStack_d8);
  }
  if ((pcVar21 != (code *)0x0) &&
     (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  if ((pcVar22 != (code *)0x0) &&
     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
  *plVar1 = *plVar1 + -1;
  pcStack_68 = pcVar19;
  auStack_78._0_8_ = uVar12;
  auStack_78._8_8_ = uVar23;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,pcStack_68);
  return (code *)0x0;
}
