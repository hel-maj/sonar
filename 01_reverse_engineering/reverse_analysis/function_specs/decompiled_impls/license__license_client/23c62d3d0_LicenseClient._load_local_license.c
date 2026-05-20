/* ===== 23c62d3d0 license.license_client:192 ===== */
/* ghidra_name=FUN_23c62d3d0 entry=23c62d3d0 size=13447 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23c62d3d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong **pplVar21;
  code *pcVar22;
  int iVar23;
  code *pcVar24;
  undefined4 uVar25;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  code *pcStack_e8;
  code *pcStack_e0;
  longlong *plStack_d8;
  code *pcStack_d0;
  longlong **pplStack_c8;
  longlong **pplStack_a8;
  code *pcStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23ee29c90;
  plVar1 = (longlong *)*param_3;
  plVar19 = (longlong *)param_3[1];
  if (_DAT_23ee29c90 == (longlong *)0x0) {
LAB_23c62d41e:
    _DAT_23ee29c90 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c88,DAT_23ee29d18);
  }
  else {
    lVar12 = *_DAT_23ee29c90;
    if (1 < lVar12) {
      *_DAT_23ee29c90 = lVar12 + -1;
      goto LAB_23c62d41e;
    }
    if (_DAT_23ee29c90[2] != 0) {
      *_DAT_23ee29c90 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23c62d41e;
    }
  }
  plVar2 = _DAT_23ee29c90;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ee29c90 + 9;
  lVar14 = *(longlong *)(lVar12 + 8);
  _DAT_23ee29c90[0xf] = lVar14;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar5 = _DAT_23ee28640;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar19,uVar5);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar2 + 5) = 0xcc;
    plVar11 = (longlong *)FUN_23e91a870(param_1,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10 = (longlong *)0x0;
    if (plVar11 == (longlong *)0x0) {
LAB_23c62d710:
      pcStack_e8 = _PyRuntime_exref;
      pcVar24 = *(code **)(param_1 + 0x70);
      plVar17 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = *(longlong **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x68);
      uVar25 = 0xcc;
      plStack_100 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c62d75e;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee28648);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23c62da20;
    *(undefined4 *)(plVar2 + 5) = 0xcc;
    plVar11 = (longlong *)FUN_23e91a870(param_1,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10 = plVar11;
    if (plVar11 == (longlong *)0x0) goto LAB_23c62d710;
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    plVar10 = (longlong *)FUN_23e8bd600(param_1,plVar11);
    pcStack_e8 = _PyRuntime_exref;
    plVar19 = plVar11;
    if (plVar10 == (longlong *)0x0) {
      plVar13 = *(longlong **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar17 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar25 = 0xce;
      plStack_100 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      goto LAB_23c62d75e;
    }
    lVar12 = *plVar10 + -1;
    if ((plVar10[2] != 1) || ((int)plVar10[3] != 0x10)) {
      *plVar10 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      plVar16 = _DAT_23ee28650;
      plVar17 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      *_DAT_23ee28650 = *_DAT_23ee28650 + 1;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23c62d5bb;
    }
    *plVar10 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    lVar12 = FUN_23ead5f40();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
      plVar18 = (longlong *)0x0;
      pcVar24 = pcStack_68;
      plVar13 = plStack_78;
      pcVar22 = pcStack_70;
LAB_23c62e819:
      pcStack_e8 = _PyRuntime_exref;
      plStack_100 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      uVar25 = 0xd1;
      plStack_108 = (longlong *)0x0;
      goto LAB_23c62d75e;
    }
    plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23ee28400);
    plVar17 = _DAT_23ee28658;
    if (plVar15 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = *(longlong **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar18 = plVar15;
      pcVar22 = *(code **)(param_1 + 0x68);
      goto LAB_23c62e819;
    }
    lVar12 = *(longlong *)(param_1 + 0x10);
    plVar19 = *(longlong **)(lVar12 + 0xe28);
    if (plVar19 == (longlong *)0x0) {
      plVar19 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar14 = plVar19[3];
      *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
      *(longlong *)(lVar12 + 0xe28) = lVar14;
      *plVar19 = 1;
    }
    pcStack_e8 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar19 + 4) = (undefined1  [16])0x0;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
    lVar14 = plVar19[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar19 + -2;
    uVar5 = _DAT_23ee28660;
    plVar19[-2] = lVar12;
    plVar19[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar19 + -2;
    *plVar17 = *plVar17 + 1;
    plVar19[3] = (longlong)plVar17;
    plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar11,uVar5);
    pcVar24 = DAT_23ed6cd28;
    if (plVar16 == (longlong *)0x0) {
LAB_23c62ed40:
      plVar13 = *(longlong **)(param_1 + 0x60);
      pcVar22 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        uVar25 = 0xd1;
        (**(code **)(plVar19[1] + 0x30))(plVar19);
        pcStack_e0 = pcVar24;
LAB_23c62ed9a:
        plStack_100 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar24 = pcStack_e0;
        plVar19 = plVar11;
      }
      else {
        uVar25 = 0xd1;
LAB_23c62ef89:
        plStack_100 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar19 = plVar11;
      }
      goto LAB_23c62d75e;
    }
    if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23c62e31e:
      pplStack_c8 = &plStack_78;
      pcStack_70 = pcVar24;
      plStack_78 = plVar16;
      lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_c8);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      plVar10 = _DAT_23ee28668;
      if (lVar12 == 0) goto LAB_23c62ed40;
      plVar19[4] = lVar12;
      *plVar10 = *plVar10 + 1;
      plVar19[5] = (longlong)plVar10;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar19);
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      if (plVar10 == (longlong *)0x0) {
        plVar13 = *(longlong **)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x68);
        pcVar24 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar15 = *plVar15 + -1;
        plStack_108 = (longlong *)0x0;
        if (*plVar15 == 0) {
          plVar17 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar25 = 0xd1;
          (**(code **)(plVar15[1] + 0x30))(plVar15);
          plStack_100 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plVar19 = plVar11;
        }
        else {
          plVar17 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          uVar25 = 0xd1;
          plStack_f8 = (longlong *)0x0;
          plVar19 = plVar11;
        }
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0xd1;
        plVar17 = (longlong *)FUN_23e914090(param_1,plVar15,plVar10);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        plStack_108 = (longlong *)*plVar10;
        *plVar10 = (longlong)plStack_108 + -1;
        if ((longlong)plStack_108 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar17 == (longlong *)0x0) {
          plVar13 = *(longlong **)(param_1 + 0x60);
          pcVar22 = *(code **)(param_1 + 0x68);
          pcVar24 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar18 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar25 = 0xd1;
          plStack_100 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar19 = plVar11;
        }
        else {
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          plVar18 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee28670);
          pcVar24 = DAT_23ed6cd28;
          if (plVar18 == (longlong *)0x0) {
LAB_23c62f376:
            plVar13 = *(longlong **)(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x68);
            pcVar24 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar17 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            uVar25 = 0xd4;
            plStack_100 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar19 = plVar11;
          }
          else {
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              plVar15 = plVar18;
              if (plVar10 == (longlong *)0x0) goto LAB_23c62f670;
              *plVar10 = *plVar10 + 1;
              DAT_23ed6a4c0 = plVar10;
            }
            pcStack_70 = pcVar24;
            plStack_78 = plVar18;
            plStack_108 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_c8);
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            if (plStack_108 != (longlong *)0x0) {
              lVar12 = *(longlong *)(param_1 + 0x10);
              plVar19 = *(longlong **)(lVar12 + 0xe30);
              if (plVar19 == (longlong *)0x0) {
                plVar19 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
              }
              else {
                lVar14 = plVar19[3];
                *(int *)(lVar12 + 0xec4) = *(int *)(lVar12 + 0xec4) + -1;
                *(longlong *)(lVar12 + 0xe30) = lVar14;
                *plVar19 = 1;
              }
              plVar19[6] = 0;
              *(undefined1 (*) [16])(plVar19 + 4) = (undefined1  [16])0x0;
              lVar12 = *(longlong *)
                        (*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
              lVar14 = plVar19[-1];
              puVar3 = *(undefined8 **)(lVar12 + 8);
              *puVar3 = plVar19 + -2;
              plVar19[-2] = lVar12;
              plVar19[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar12 + 8) = plVar19 + -2;
              uVar5 = _DAT_23ee28678;
              plVar19[3] = (longlong)plStack_108;
              plVar10 = DAT_23ed6cea0;
              *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
              plVar19[4] = (longlong)plVar10;
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
              pcVar24 = DAT_23ed6cd28;
              if (plVar15 != (longlong *)0x0) {
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar10 == (longlong *)0x0) goto LAB_23c62f670;
                  *plVar10 = *plVar10 + 1;
                  DAT_23ed6a4c0 = plVar10;
                }
                pcStack_70 = pcVar24;
                plStack_78 = plVar15;
                lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_c8);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                plVar10 = _DAT_23ee28680;
                if (lVar12 != 0) {
                  plVar19[5] = lVar12;
                  *plVar10 = *plVar10 + 1;
                  plVar19[6] = (longlong)plVar10;
                  plVar18 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar19);
                  *plVar19 = *plVar19 + -1;
                  if (*plVar19 == 0) {
                    FUN_23a334bc0(plVar19);
                  }
                  uVar5 = DAT_23ee28688;
                  if (plVar18 == (longlong *)0x0) goto LAB_23c62f376;
                  plVar10 = (longlong *)_PyDict_NewPresized(2);
                  PyDict_SetItem(plVar10,uVar5,plVar11);
                  uVar5 = DAT_23ee28450;
                  plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
                  if (plVar19 == (longlong *)0x0) {
                    lVar12 = *plVar10;
                    plVar13 = *(longlong **)(param_1 + 0x60);
                    pcVar22 = *(code **)(param_1 + 0x68);
                    pcVar24 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar10 = lVar12 + -1;
                    plStack_108 = (longlong *)0x0;
                    if (lVar12 + -1 == 0) {
                      plVar17 = (longlong *)0x0;
                      uVar25 = 0xd7;
                      FUN_23a334bc0(plVar10);
                      plStack_100 = (longlong *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      plVar19 = plVar11;
                    }
                    else {
                      plVar17 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      plStack_100 = (longlong *)0x0;
                      uVar25 = 0xd7;
                      plStack_f8 = (longlong *)0x0;
                      plVar19 = plVar11;
                    }
                  }
                  else {
                    PyDict_SetItem(plVar10,uVar5,plVar19);
                    lVar12 = *plVar19;
                    *plVar19 = lVar12 + -1;
                    if (lVar12 + -1 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    lVar12 = FUN_23ead5a00();
                    if (lVar12 == 0) {
                      FUN_23e915740(param_1,pplStack_c8,_DAT_23ee28690);
                      plStack_108 = (longlong *)0x0;
                      pcVar24 = pcStack_68;
                      plVar13 = plStack_78;
                      pcVar22 = pcStack_70;
LAB_23c62f843:
                      plVar17 = (longlong *)0x0;
                      uVar25 = 0xda;
                      plStack_100 = (longlong *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      plVar19 = plVar11;
                    }
                    else {
                      plVar19 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23ee28698);
                      uVar5 = _DAT_23ee286a8;
                      pcVar24 = _DAT_23ee286a0;
                      if (plVar19 == (longlong *)0x0) {
                        plVar13 = *(longlong **)(param_1 + 0x60);
                        pcVar22 = *(code **)(param_1 + 0x68);
                        pcVar24 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar25 = 0xda;
                        plStack_100 = (longlong *)0x0;
                        plStack_f8 = (longlong *)0x0;
                        plStack_108 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar17 = (longlong *)0x0;
                        plVar19 = plVar11;
                      }
                      else {
                        *(undefined4 *)(plVar2 + 5) = 0xda;
                        auStack_98._0_8_ = plVar18;
                        pcStack_70 = pcVar24;
                        plStack_78 = plVar10;
                        plStack_108 = (longlong *)
                                      FUN_23e939900(param_1,plVar19,auStack_98,pplStack_c8,uVar5);
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        if (plStack_108 == (longlong *)0x0) {
                          pcVar24 = *(code **)(param_1 + 0x70);
                          plVar13 = *(longlong **)(param_1 + 0x60);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pcVar22 = *(code **)(param_1 + 0x68);
                          goto LAB_23c62f843;
                        }
                        plVar19 = (longlong *)FUN_23e8bc2f0(plStack_108,_DAT_23ee286b0);
                        if (plVar19 == (longlong *)0x0) {
                          plVar13 = *(longlong **)(param_1 + 0x60);
                          pcVar22 = *(code **)(param_1 + 0x68);
                          pcVar24 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar25 = 0xdc;
                          plStack_100 = (longlong *)0x0;
                          plStack_f8 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar17 = (longlong *)0x0;
                          plVar19 = plVar11;
                        }
                        else {
                          iVar9 = FUN_23e97a530(plVar19,_DAT_23ee286b8);
                          *plVar19 = *plVar19 + -1;
                          if (*plVar19 == 0) {
                            FUN_23a334bc0();
                          }
                          if (iVar9 == -1) {
                            plVar13 = *(longlong **)(param_1 + 0x60);
                            pcVar22 = *(code **)(param_1 + 0x68);
                            pcVar24 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar17 = (longlong *)0x0;
                            plStack_100 = (longlong *)0x0;
                            uVar25 = 0xdc;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar19 = plVar11;
                          }
                          else if (iVar9 == 1) {
                            *(undefined4 *)(plVar2 + 5) = 0xdd;
                            plVar17 = (longlong *)FUN_23e91bfe0(param_1,plStack_108,_DAT_23ee28488);
                            if (plVar17 == (longlong *)0x0) {
                              plVar13 = *(longlong **)(param_1 + 0x60);
                              pcVar22 = *(code **)(param_1 + 0x68);
                              pcVar24 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar25 = 0xdd;
                              plStack_100 = (longlong *)0x0;
                              plStack_f8 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar19 = plVar11;
                            }
                            else {
                              cVar8 = FUN_23e8d9ac0(plVar1,DAT_23ee28390,plVar11);
                              uVar5 = DAT_23ee28688;
                              if (cVar8 == '\0') {
                                pcVar24 = *(code **)(param_1 + 0x70);
                                plVar13 = *(longlong **)(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar25 = 0xe0;
                                plStack_100 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar19 = plVar11;
                                pcVar22 = *(code **)(param_1 + 0x68);
                              }
                              else {
                                plVar19 = (longlong *)_PyDict_NewPresized(4);
                                PyDict_SetItem(plVar19,uVar5,plVar11);
                                uVar5 = DAT_23ee28450;
                                plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
                                if (plVar13 == (longlong *)0x0) {
                                  plVar13 = *(longlong **)(param_1 + 0x60);
                                  pcVar22 = *(code **)(param_1 + 0x68);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  uVar25 = 0xe3;
                                }
                                else {
                                  PyDict_SetItem(plVar19,uVar5,plVar13);
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  uVar6 = DAT_23ee286c0;
                                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar17,DAT_23ed6ce40);
                                  uVar5 = DAT_23ee28578;
                                  if (plVar13 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar2 + 5) = 0xe4;
                                    plVar15 = (longlong *)FUN_23e94bb80(param_1,plVar13,uVar5);
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    if (plVar15 != (longlong *)0x0) {
                                      PyDict_SetItem(plVar19,uVar6);
                                      *plVar15 = *plVar15 + -1;
                                      if (*plVar15 == 0) {
                                        FUN_23a334bc0(plVar15);
                                      }
                                      uVar5 = DAT_23ee286c8;
                                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar17,DAT_23ed6ce40);
                                      uVar6 = DAT_23ee286d0;
                                      if (plVar13 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar2 + 5) = 0xe5;
                                        plVar15 = (longlong *)FUN_23e94bb80(param_1,plVar13,uVar6);
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        if (plVar15 != (longlong *)0x0) {
                                          PyDict_SetItem(plVar19,uVar5);
                                          *plVar15 = *plVar15 + -1;
                                          if (*plVar15 == 0) {
                                            FUN_23a334bc0(plVar15);
                                          }
                                          cVar8 = FUN_23e8d9ac0(plVar1,DAT_23ee283a8,plVar19);
                                          *plVar19 = *plVar19 + -1;
                                          if (*plVar19 == 0) {
                                            FUN_23a334bc0(plVar19);
                                          }
                                          pcVar24 = _Py_TrueStruct_exref;
                                          if (cVar8 == '\0') {
                                            plVar13 = *(longlong **)(param_1 + 0x60);
                                            pcVar24 = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar25 = 0xe1;
                                            plStack_100 = (longlong *)0x0;
                                            plStack_f8 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plVar19 = plVar11;
                                            pcVar22 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            cVar8 = FUN_23e8d9ac0(plVar1,DAT_23ee283b0);
                                            if (cVar8 == '\0') {
                                              plVar13 = *(longlong **)(param_1 + 0x60);
                                              pcVar24 = *(code **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar25 = 0xe7;
                                              plStack_100 = (longlong *)0x0;
                                              plStack_f8 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plVar19 = plVar11;
                                              pcVar22 = *(code **)(param_1 + 0x68);
                                            }
                                            else {
                                              plVar19 = (longlong *)
                                                        FUN_23e8bc2f0(plVar1,_DAT_23ee286d8);
                                              if (plVar19 == (longlong *)0x0) {
                                                plVar13 = *(longlong **)(param_1 + 0x60);
                                                pcVar22 = *(code **)(param_1 + 0x68);
                                                pcVar24 = *(code **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                uVar25 = 0xea;
                                                plStack_f8 = (longlong *)0x0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                plStack_100 = (longlong *)0x0;
                                                plVar19 = plVar11;
                                              }
                                              else {
                                                plVar13 = (longlong *)
                                                          FUN_23e8bc2f0(plVar1,DAT_23ee283a8);
                                                if (plVar13 == (longlong *)0x0) {
                                                  pcVar24 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  plVar13 = *(longlong **)(param_1 + 0x60);
                                                  pcVar22 = *(code **)(param_1 + 0x68);
                                                  lVar12 = *plVar19;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar19 = lVar12 + -1;
                                                  plStack_f8 = (longlong *)0x0;
                                                  if (lVar12 + -1 == 0) {
                                                    uVar25 = 0xea;
                                                    FUN_23a334bc0();
                                                    plStack_100 = (longlong *)0x0;
                                                    plVar19 = plVar11;
                                                  }
                                                  else {
                                                    uVar25 = 0xea;
                                                    plStack_100 = (longlong *)0x0;
                                                    plVar19 = plVar11;
                                                  }
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0xea;
                                                  plVar15 = (longlong *)
                                                            FUN_23e914090(param_1,plVar19,plVar13);
                                                  lVar12 = *plVar19;
                                                  *plVar19 = lVar12 + -1;
                                                  if (lVar12 + -1 == 0) {
                                                    FUN_23a334bc0(plVar19);
                                                  }
                                                  lVar12 = *plVar13;
                                                  *plVar13 = lVar12 + -1;
                                                  if (lVar12 + -1 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  if (plVar15 == (longlong *)0x0) {
                                                    plVar13 = *(longlong **)(param_1 + 0x60);
                                                    pcVar22 = *(code **)(param_1 + 0x68);
                                                    pcVar24 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar25 = 0xea;
                                                    plStack_100 = (longlong *)0x0;
                                                    plStack_f8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar19 = plVar11;
                                                  }
                                                  else {
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 == 0) {
                                                      FUN_23a334bc0(plVar15);
                                                    }
                                                    plVar19 = (longlong *)
                                                              FUN_23e8bc2f0(plVar17,DAT_23ed6ce40);
                                                    if (plVar19 == (longlong *)0x0) {
                                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                                      pcVar22 = *(code **)(param_1 + 0x68);
                                                      pcVar24 = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar25 = 0xec;
                                                      plStack_f8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_100 = (longlong *)0x0;
                                                      plVar19 = plVar11;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar2 + 5) = 0xec;
                                                      plStack_f8 = (longlong *)
                                                                   FUN_23e9557e0(param_1,plVar19,
                                                                                 _DAT_23ee286e0);
                                                      lVar12 = *plVar19;
                                                      *plVar19 = lVar12 + -1;
                                                      if (lVar12 + -1 == 0) {
                                                        FUN_23a334bc0(plVar19);
                                                      }
                                                      if (plStack_f8 == (longlong *)0x0) {
                                                        plVar13 = *(longlong **)(param_1 + 0x60);
                                                        pcVar22 = *(code **)(param_1 + 0x68);
                                                        pcVar24 = *(code **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        uVar25 = 0xec;
                                                        plStack_100 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar19 = plVar11;
                                                      }
                                                      else {
                                                        lVar12 = FUN_23ead5f40();
                                                        if (lVar12 == 0) {
                                                          uVar25 = 0xed;
                                                          FUN_23e915740(param_1,pplStack_c8,
                                                                        DAT_23ee283f8);
                                                          plStack_100 = (longlong *)0x0;
                                                          pcVar24 = pcStack_68;
                                                          plVar19 = plVar11;
                                                          plVar13 = plStack_78;
                                                          pcVar22 = pcStack_70;
                                                        }
                                                        else {
                                                          plVar19 = (longlong *)
                                                                    FUN_23e8bc2f0(lVar12,
                                                  DAT_23ee28400);
                                                  plVar13 = _DAT_23ee286e8;
                                                  if (plVar19 == (longlong *)0x0) {
LAB_23c63029f:
                                                    plVar13 = *(longlong **)(param_1 + 0x60);
                                                    pcVar24 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar25 = 0xed;
                                                    plStack_100 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar19 = plVar11;
                                                    pcVar22 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    plVar15 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),2);
                                                    *plVar13 = *plVar13 + 1;
                                                    plVar15[3] = (longlong)plVar13;
                                                    lVar12 = FUN_23e94f9d0(param_1,plStack_f8,
                                                                           DAT_23ed6cd28);
                                                    if (lVar12 == 0) {
                                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                                      pcVar22 = *(code **)(param_1 + 0x68);
                                                      pcVar24 = *(code **)(param_1 + 0x70);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *plVar19 = *plVar19 + -1;
                                                      if (*plVar19 == 0) {
                                                        FUN_23a334bc0(plVar19);
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      lVar12 = *plVar15;
                                                      plVar19 = plVar15;
                                                    }
                                                    else {
                                                      plVar15[4] = lVar12;
                                                      plVar13 = (longlong *)
                                                                PyUnicode_Join(DAT_23ed6cd28,plVar15
                                                                              );
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      if (plVar13 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar2 + 5) = 0xed;
                                                        plVar15 = (longlong *)
                                                                  FUN_23e914090(param_1,plVar19,
                                                                                plVar13);
                                                        *plVar19 = *plVar19 + -1;
                                                        if (*plVar19 == 0) {
                                                          FUN_23a334bc0(plVar19);
                                                        }
                                                        lVar12 = *plVar13;
                                                        *plVar13 = lVar12 + -1;
                                                        if (lVar12 + -1 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          plVar16 = (longlong *)
                                                                    FUN_23e916ad0(*(undefined8 *)
                                                                                   (param_1 + 0x10),
                                                                                  2);
                                                          plVar19 = _DAT_23ee286f0;
                                                          uVar5 = *(undefined8 *)(param_1 + 0x10);
                                                          plVar16[3] = (longlong)pcVar24;
                                                          *(longlong *)pcVar24 =
                                                               *(longlong *)pcVar24 + 1;
                                                          plVar15 = (longlong *)
                                                                    FUN_23e916ad0(uVar5,2);
                                                          *plVar19 = *plVar19 + 1;
                                                          plVar15[3] = (longlong)plVar19;
                                                          lVar12 = FUN_23e94f9d0(param_1,plStack_f8)
                                                          ;
                                                          if (lVar12 == 0) {
                                                            plVar13 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            pcVar22 = *(code **)(param_1 + 0x68);
                                                            pcVar24 = *(code **)(param_1 + 0x70);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                          }
                                                          else {
                                                            plVar15[4] = lVar12;
                                                            lVar12 = PyUnicode_Join(DAT_23ed6cd28,
                                                                                    plVar15);
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            if (lVar12 != 0) {
                                                              plVar16[4] = lVar12;
                                                              plStack_100 = (longlong *)0x0;
                                                              goto LAB_23c62d5bb;
                                                            }
                                                            plVar13 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            pcVar22 = *(code **)(param_1 + 0x68);
                                                            pcVar24 = *(code **)(param_1 + 0x70);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                          }
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            uVar25 = 0xef;
                                                            FUN_23a334bc0(plVar16);
                                                            plStack_100 = (longlong *)0x0;
                                                            plVar19 = plVar11;
                                                          }
                                                          else {
                                                            uVar25 = 0xef;
                                                            plStack_100 = (longlong *)0x0;
                                                            plVar19 = plVar11;
                                                          }
                                                          goto LAB_23c62d75e;
                                                        }
                                                        goto LAB_23c63029f;
                                                      }
                                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                                      pcVar22 = *(code **)(param_1 + 0x68);
                                                      pcVar24 = *(code **)(param_1 + 0x70);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *plVar19 = *plVar19 + -1;
                                                      lVar12 = *plVar19;
                                                    }
                                                    if (lVar12 == 0) {
                                                      plStack_100 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar19);
                                                      uVar25 = 0xed;
                                                      plVar19 = plVar11;
                                                    }
                                                    else {
                                                      plStack_100 = (longlong *)0x0;
                                                      uVar25 = 0xed;
                                                      plVar19 = plVar11;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                          goto LAB_23c62d75e;
                                        }
                                      }
                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                      pcVar22 = *(code **)(param_1 + 0x68);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      uVar25 = 0xe5;
                                      goto LAB_23c62fb27;
                                    }
                                  }
                                  plVar13 = *(longlong **)(param_1 + 0x60);
                                  pcVar22 = *(code **)(param_1 + 0x68);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  uVar25 = 0xe4;
                                }
LAB_23c62fb27:
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  FUN_23a334bc0(plVar19);
                                  plStack_100 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  plVar19 = plVar11;
                                }
                                else {
                                  plStack_100 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  plVar19 = plVar11;
                                }
                              }
                            }
                          }
                          else {
                            plVar19 = (longlong *)FUN_23e8bc2f0(plStack_108,_DAT_23ee286b0);
                            if (plVar19 == (longlong *)0x0) {
                              plVar13 = *(longlong **)(param_1 + 0x60);
                              pcVar24 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar25 = 0xf1;
                              plStack_100 = (longlong *)0x0;
                              plStack_f8 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar17 = (longlong *)0x0;
                              plVar19 = plVar11;
                              pcVar22 = *(code **)(param_1 + 0x68);
                            }
                            else {
                              iVar9 = FUN_23e97a530(plVar19,_DAT_23ee286f8);
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              plVar16 = _DAT_23ee28700;
                              if (iVar9 == -1) {
                                pcVar24 = *(code **)(param_1 + 0x70);
                                plVar13 = *(longlong **)(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar25 = 0xf1;
                                plStack_100 = (longlong *)0x0;
                                plVar17 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar19 = plVar11;
                                pcVar22 = *(code **)(param_1 + 0x68);
                              }
                              else {
                                if (iVar9 == 1) {
                                  *_DAT_23ee28700 = *_DAT_23ee28700 + 1;
LAB_23c62e7b4:
                                  plVar17 = (longlong *)0x0;
                                  plStack_100 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  goto LAB_23c62d5bb;
                                }
                                plVar19 = (longlong *)FUN_23e8bc2f0(plStack_108,_DAT_23ee286b0);
                                if (plVar19 == (longlong *)0x0) {
                                  plVar13 = *(longlong **)(param_1 + 0x60);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar25 = 0xf3;
                                  plStack_100 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar17 = (longlong *)0x0;
                                  plVar19 = plVar11;
                                  pcVar22 = *(code **)(param_1 + 0x68);
                                }
                                else {
                                  iVar9 = FUN_23e97a530(plVar19,_DAT_23ee28708);
                                  *plVar19 = *plVar19 + -1;
                                  if (*plVar19 == 0) {
                                    FUN_23a334bc0(plVar19);
                                  }
                                  if (iVar9 == -1) {
                                    plVar13 = *(longlong **)(param_1 + 0x60);
                                    pcVar24 = *(code **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plVar17 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                    uVar25 = 0xf3;
                                    plStack_f8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar19 = plVar11;
                                    pcVar22 = *(code **)(param_1 + 0x68);
                                  }
                                  else if (iVar9 == 1) {
                                    *(undefined4 *)(plVar2 + 5) = 0xf4;
                                    plVar19 = (longlong *)
                                              FUN_23e91bfe0(param_1,plStack_108,_DAT_23ee28488);
                                    if (plVar19 == (longlong *)0x0) {
                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      plStack_100 = (longlong *)0x0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      plStack_f8 = (longlong *)0x0;
                                      uVar25 = 0xf4;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plVar17 = (longlong *)0x0;
                                      plVar19 = plVar11;
                                      pcVar22 = *(code **)(param_1 + 0x68);
                                    }
                                    else {
                                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23ed6ce40);
                                      *plVar19 = *plVar19 + -1;
                                      if (*plVar19 == 0) {
                                        FUN_23a334bc0(plVar19);
                                      }
                                      if (plVar13 == (longlong *)0x0) {
                                        plVar13 = *(longlong **)(param_1 + 0x60);
                                        pcVar24 = *(code **)(param_1 + 0x70);
                                        plStack_100 = (longlong *)0x0;
                                        plVar17 = (longlong *)0x0;
                                        uVar25 = 0xf4;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_f8 = (longlong *)0x0;
                                        plVar19 = plVar11;
                                        pcVar22 = *(code **)(param_1 + 0x68);
                                      }
                                      else {
                                        *(undefined4 *)(plVar2 + 5) = 0xf4;
                                        plStack_100 = (longlong *)FUN_23e9557e0(param_1,plVar13);
                                        lVar12 = *plVar13;
                                        *plVar13 = lVar12 + -1;
                                        if (lVar12 + -1 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        uVar5 = _DAT_23ee28718;
                                        if (plStack_100 == (longlong *)0x0) {
                                          plVar13 = *(longlong **)(param_1 + 0x60);
                                          pcVar24 = *(code **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar17 = (longlong *)0x0;
                                          uVar25 = 0xf4;
                                          plStack_f8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar19 = plVar11;
                                          pcVar22 = *(code **)(param_1 + 0x68);
                                        }
                                        else {
                                          plVar19 = (longlong *)
                                                    FUN_23e8bc2f0(plStack_100,DAT_23ed6ce98);
                                          if (plVar19 == (longlong *)0x0) {
                                            plVar13 = *(longlong **)(param_1 + 0x60);
                                            pcVar24 = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            plVar17 = (longlong *)0x0;
                                            uVar25 = 0xf5;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plStack_f8 = (longlong *)0x0;
                                            plVar19 = plVar11;
                                            pcVar22 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            *(undefined4 *)(plVar2 + 5) = 0xf5;
                                            plVar13 = (longlong *)FUN_23e91a870(param_1,plVar19);
                                            lVar12 = *plVar19;
                                            *plVar19 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              FUN_23a334bc0(plVar19);
                                            }
                                            if (plVar13 == (longlong *)0x0) {
                                              plVar13 = *(longlong **)(param_1 + 0x60);
                                              pcVar24 = *(code **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar25 = 0xf5;
                                              plStack_f8 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plVar17 = (longlong *)0x0;
                                              plVar19 = plVar11;
                                              pcVar22 = *(code **)(param_1 + 0x68);
                                            }
                                            else {
                                              iVar9 = PySequence_Contains(plVar13,uVar5);
                                              *plVar13 = *plVar13 + -1;
                                              if (*plVar13 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              uVar5 = _DAT_23ee28728;
                                              if (iVar9 == -1) {
                                                plVar13 = *(longlong **)(param_1 + 0x60);
                                                pcVar24 = *(code **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                plVar17 = (longlong *)0x0;
                                                plStack_f8 = (longlong *)0x0;
                                                uVar25 = 0xf5;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                plVar19 = plVar11;
                                                pcVar22 = *(code **)(param_1 + 0x68);
                                              }
                                              else {
                                                plVar16 = _DAT_23ee28720;
                                                if (iVar9 == 1) {
LAB_23c630607:
                                                  *plVar16 = *plVar16 + 1;
                                                  plVar17 = (longlong *)0x0;
                                                  plStack_f8 = (longlong *)0x0;
                                                  goto LAB_23c62d5bb;
                                                }
                                                plVar19 = (longlong *)
                                                          FUN_23e8bc2f0(plStack_100,DAT_23ed6ce98);
                                                if (plVar19 == (longlong *)0x0) {
                                                  plVar13 = *(longlong **)(param_1 + 0x60);
                                                  pcVar24 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  plVar17 = (longlong *)0x0;
                                                  uVar25 = 0xf7;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_f8 = (longlong *)0x0;
                                                  plVar19 = plVar11;
                                                  pcVar22 = *(code **)(param_1 + 0x68);
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0xf7;
                                                  plVar13 = (longlong *)
                                                            FUN_23e91a870(param_1,plVar19);
                                                  lVar12 = *plVar19;
                                                  *plVar19 = lVar12 + -1;
                                                  if (lVar12 + -1 == 0) {
                                                    FUN_23a334bc0(plVar19);
                                                  }
                                                  if (plVar13 == (longlong *)0x0) {
                                                    plVar13 = *(longlong **)(param_1 + 0x60);
                                                    pcVar24 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar25 = 0xf7;
                                                    plStack_f8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar17 = (longlong *)0x0;
                                                    plVar19 = plVar11;
                                                    pcVar22 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    iVar9 = PySequence_Contains(plVar13,uVar5);
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    if (iVar9 != -1) {
                                                      plVar16 = _DAT_23ee28730;
                                                      if (iVar9 != 1) {
                                                        plVar17 = (longlong *)0x0;
                                                        plVar16 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),2)
                                                        ;
                                                        pcVar24 = _Py_FalseStruct_exref;
                                                        plStack_f8 = (longlong *)0x0;
                                                        *(longlong *)_Py_FalseStruct_exref =
                                                             *(longlong *)_Py_FalseStruct_exref + 1;
                                                        plVar16[3] = (longlong)pcVar24;
                                                        *plStack_100 = *plStack_100 + 1;
                                                        plVar16[4] = (longlong)plStack_100;
                                                        goto LAB_23c62d5bb;
                                                      }
                                                      goto LAB_23c630607;
                                                    }
                                                    pcVar24 = *(code **)(param_1 + 0x70);
                                                    plVar13 = *(longlong **)(param_1 + 0x60);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar25 = 0xf7;
                                                    plStack_f8 = (longlong *)0x0;
                                                    plVar17 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar19 = plVar11;
                                                    pcVar22 = *(code **)(param_1 + 0x68);
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  else {
                                    plVar16 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                    pcVar24 = _Py_FalseStruct_exref;
                                    plVar19 = _DAT_23ee28738;
                                    uVar5 = *(undefined8 *)(param_1 + 0x10);
                                    plVar16[3] = (longlong)_Py_FalseStruct_exref;
                                    *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                                    plVar17 = (longlong *)FUN_23e916ad0(uVar5,2);
                                    *plVar19 = *plVar19 + 1;
                                    plVar17[3] = (longlong)plVar19;
                                    plVar19 = (longlong *)FUN_23e8bc2f0(plStack_108,_DAT_23ee286b0);
                                    if (plVar19 == (longlong *)0x0) {
LAB_23c62fd83:
                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                      pcVar22 = *(code **)(param_1 + 0x68);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                    }
                                    else {
                                      lVar12 = FUN_23e94f9d0(param_1,plVar19,DAT_23ed6cd28);
                                      *plVar19 = *plVar19 + -1;
                                      if (*plVar19 == 0) {
                                        FUN_23a334bc0(plVar19);
                                      }
                                      if (lVar12 == 0) goto LAB_23c62fd83;
                                      plVar17[4] = lVar12;
                                      lVar12 = PyUnicode_Join(DAT_23ed6cd28,plVar17);
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                      if (lVar12 != 0) {
                                        plVar16[4] = lVar12;
                                        goto LAB_23c62e7b4;
                                      }
                                      plVar13 = *(longlong **)(param_1 + 0x60);
                                      pcVar22 = *(code **)(param_1 + 0x68);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                    }
                                    *plVar16 = *plVar16 + -1;
                                    if (*plVar16 == 0) {
                                      FUN_23a334bc0(plVar16);
                                    }
                                    uVar25 = 0xfb;
                                    plVar17 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                    plStack_f8 = (longlong *)0x0;
                                    plVar19 = plVar11;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_23c62d75e;
                }
              }
              plVar13 = *(longlong **)(param_1 + 0x60);
              pcVar22 = *(code **)(param_1 + 0x68);
              pcVar24 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar19 = *plVar19 + -1;
              if (*plVar19 != 0) {
                uVar25 = 0xd4;
                goto LAB_23c62ef89;
              }
              uVar25 = 0xd4;
              (**(code **)(plVar19[1] + 0x30))(plVar19);
              pcStack_e0 = pcVar24;
              goto LAB_23c62ed9a;
            }
            plVar13 = *(longlong **)(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x68);
            pcVar24 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar17 = (longlong *)0x0;
            plVar18 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            uVar25 = 0xd4;
            plStack_f8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar19 = plVar11;
          }
        }
      }
      goto LAB_23c62d75e;
    }
    plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
      DAT_23ed6a4c0 = plVar10;
      goto LAB_23c62e31e;
    }
LAB_23c62f670:
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23c62f683:
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcVar24 = *(code **)(param_1 + 0x70);
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = plVar11;
    plVar18 = plVar15;
LAB_23c62f2c8:
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    iVar23 = 0x103;
    goto LAB_23c62f150;
  }
LAB_23c62da20:
  pcStack_e8 = _PyRuntime_exref;
  plVar18 = (longlong *)0x0;
  plVar17 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  plVar13 = *(longlong **)(param_1 + 0x60);
  pcVar22 = *(code **)(param_1 + 0x68);
  pcVar24 = *(code **)(param_1 + 0x70);
  plStack_100 = (longlong *)0x0;
  uVar25 = 0xcc;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plStack_f8 = (longlong *)0x0;
  plStack_108 = (longlong *)0x0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c62d75e:
  pcStack_e0 = *(code **)(param_1 + 0x138);
  auStack_98._8_8_ = pcVar22;
  auStack_98._0_8_ = plVar13;
  if (pcStack_e0 != (code *)0x0) {
    *(longlong *)pcStack_e0 = *(longlong *)pcStack_e0 + 1;
  }
  pcVar22 = DAT_23ed6a4f8;
  apcStack_88[0] = pcVar24;
  if (pcVar24 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar24 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar24;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar22 + 0x10) = 0;
    *(longlong **)(pcVar22 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar12 = *(longlong *)(pcStack_e8 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(pcVar22 + 0x24) = uVar25;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar14 = *(longlong *)(pcVar22 + -8);
    plVar11 = *(longlong **)(lVar12 + 8);
    *plVar11 = (longlong)(pcVar22 + -0x10);
    *(longlong *)(pcVar22 + -0x10) = lVar12;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
    *(code **)(lVar12 + 8) = pcVar22 + -0x10;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar7 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar22 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar12 = *(longlong *)(pcStack_e8 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    *(undefined4 *)(pcVar22 + 0x24) = uVar25;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar22 + -8);
    plVar11 = *(longlong **)(lVar12 + 8);
    *plVar11 = (longlong)(pcVar22 + -0x10);
    *(longlong *)(pcVar22 + -0x10) = lVar12;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
    *(code **)(lVar12 + 8) = pcVar22 + -0x10;
    *(code **)(pcVar22 + 0x10) = pcVar24;
    *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
  }
  pcVar24 = _Py_NoneStruct_exref;
  apcStack_88[0] = pcVar22;
  if (((code *)auStack_98._0_8_ != (code *)0x0) &&
     ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
  }
  plVar11 = *(longlong **)(auStack_98._8_8_ + 0x28);
  if (apcStack_88[0] == pcVar24) {
    pcVar22 = (code *)0x0;
  }
  else {
    pcVar22 = apcStack_88[0];
    if (apcStack_88[0] != (code *)0x0) {
      *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
    }
  }
  *(code **)(auStack_98._8_8_ + 0x28) = pcVar22;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  plVar11 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
  if (*(longlong *)auStack_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_88[0] != (code *)0x0) &&
     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
     *(longlong *)apcStack_88[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
  }
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  uVar5 = *(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8);
  lVar12 = FUN_23ead5a00();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,&plStack_78,_DAT_23ee28690);
    plStack_d8 = plStack_78;
    pcStack_d0 = pcStack_70;
LAB_23c62e06c:
    pcVar22 = *(code **)(param_1 + 0x138);
    *(code **)(param_1 + 0x138) = pcStack_e0;
    pcVar24 = pcStack_68;
joined_r0x00023c62e085:
    if (pcVar22 == (code *)0x0) {
      if (pcVar24 == (code *)0x0) {
LAB_23c62e891:
        iVar23 = 0xfd;
        goto LAB_23c62e0b0;
      }
      iVar9 = 0xfd;
LAB_23c62e1e5:
      plVar11 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023c62e1e9:
      pcVar22 = pcVar24;
      if (plVar11 == plVar2) goto LAB_23c62de20;
    }
    else {
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
      if (*(longlong *)pcVar22 == 0) {
LAB_23c62dd41:
        iVar23 = 0xfd;
        goto LAB_23c62dd46;
      }
      iVar9 = 0xfd;
      iVar23 = 0xfd;
joined_r0x00023c62e09d:
      if (pcVar24 == (code *)0x0) goto LAB_23c62e0b0;
LAB_23c62dd65:
      pcVar22 = pcVar24;
      if (*(longlong **)(pcVar24 + 0x18) == plVar2) goto LAB_23c62de20;
      if (iVar9 == 0) {
        iVar9 = (int)plVar2[5];
      }
    }
    pcVar22 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar7 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar22 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    *(int *)(pcVar22 + 0x24) = iVar9;
    lVar12 = *(longlong *)(pcStack_e8 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar22 + -8);
    plVar11 = *(longlong **)(lVar12 + 8);
    *plVar11 = (longlong)(pcVar22 + -0x10);
    *(longlong *)(pcVar22 + -0x10) = lVar12;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
    lVar14 = *(longlong *)pcVar24;
    *(code **)(lVar12 + 8) = pcVar22 + -0x10;
    *(code **)(pcVar22 + 0x10) = pcVar24;
    if (lVar14 == 0) {
      (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
    }
    goto LAB_23c62de20;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23ee28740);
  if (plVar11 == (longlong *)0x0) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x138);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(code **)(param_1 + 0x138) = pcStack_e0;
    if (pcVar22 != (code *)0x0) {
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
      if (*(longlong *)pcVar22 != 0) {
        if (pcVar24 != (code *)0x0) {
          iVar9 = 0xfd;
          goto LAB_23c62dd65;
        }
        goto LAB_23c62e891;
      }
      goto LAB_23c62dd41;
    }
    iVar9 = 0xfd;
    if (pcVar24 == (code *)0x0) goto LAB_23c62e891;
    goto LAB_23c62e1e5;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee28748);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  if (plVar13 == (longlong *)0x0) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23c62e06c;
  }
  iVar9 = FUN_23a35ebd0(param_1,uVar5);
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar16 = _DAT_23ee28750;
  pcVar22 = *(code **)(param_1 + 0x138);
  if (iVar9 == -1) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(code **)(param_1 + 0x138) = pcStack_e0;
    goto joined_r0x00023c62e085;
  }
  if (iVar9 != 0) {
    *_DAT_23ee28750 = *_DAT_23ee28750 + 1;
LAB_23c62d9eb:
    plVar2 = *(longlong **)(param_1 + 0x138);
    *(code **)(param_1 + 0x138) = pcStack_e0;
    plVar11 = plVar19;
    if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
      (**(code **)(plVar2[1] + 0x30))();
    }
LAB_23c62d5bb:
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar19 = *(longlong **)(lVar12 + 0x28);
    plVar2 = (longlong *)plVar19[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar19 + 8) = 0xffffffff;
    if (plVar2 != (longlong *)0x0) {
      plVar19[2] = 0;
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))();
      }
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    plVar19[0xf] = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    if ((plStack_f8 != (longlong *)0x0) &&
       (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
    }
    if ((plStack_100 != (longlong *)0x0) &&
       (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_100[1] + 0x30))(plStack_100);
    }
    lVar12 = *plVar1;
    *plVar1 = lVar12 + -1;
    if (lVar12 + -1 != 0) {
      return plVar16;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return plVar16;
  }
  lVar12 = *(longlong *)(pcVar22 + 8);
  lVar14 = FUN_23ead5a00();
  if (lVar14 == 0) {
    FUN_23e915740(param_1,&plStack_78,_DAT_23ee28690);
    plStack_d8 = plStack_78;
    pcStack_d0 = pcStack_70;
LAB_23c62ee74:
    pcVar22 = *(code **)(param_1 + 0x138);
    *(code **)(param_1 + 0x138) = pcStack_e0;
    if (pcVar22 == (code *)0x0) {
LAB_23c62ef64:
      if (pcStack_68 != (code *)0x0) {
        iVar9 = 0xff;
        pcVar24 = pcStack_68;
        goto LAB_23c62e1e5;
      }
LAB_23c62f04c:
      iVar23 = 0xff;
      goto LAB_23c62e0b0;
    }
LAB_23c62ee93:
    *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
    pcVar24 = pcStack_68;
    if (*(longlong *)pcVar22 == 0) {
LAB_23c62ee38:
      iVar23 = 0xff;
      goto LAB_23c62dd46;
    }
    iVar9 = 0xff;
    iVar23 = 0xff;
    goto joined_r0x00023c62e09d;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23ee28740);
  if (plVar11 == (longlong *)0x0) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x138);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(code **)(param_1 + 0x138) = pcStack_e0;
    if (pcVar22 == (code *)0x0) {
      iVar9 = 0xff;
      if (pcVar24 != (code *)0x0) goto LAB_23c62e1e5;
      goto LAB_23c62f04c;
    }
    *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
    if (*(longlong *)pcVar22 == 0) goto LAB_23c62ee38;
    if (pcVar24 == (code *)0x0) goto LAB_23c62f04c;
    iVar9 = 0xff;
    goto LAB_23c62dd65;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee28758);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  if (plVar13 == (longlong *)0x0) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23c62ee74;
  }
  iVar9 = FUN_23a35ebd0(param_1,lVar12);
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar16 = _DAT_23ee28760;
  pcVar22 = *(code **)(param_1 + 0x138);
  if (iVar9 == -1) {
    plStack_d8 = *(longlong **)(param_1 + 0x60);
    pcStack_68 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_d0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(code **)(param_1 + 0x138) = pcStack_e0;
    if (pcVar22 != (code *)0x0) goto LAB_23c62ee93;
    goto LAB_23c62ef64;
  }
  if (iVar9 != 0) {
    *_DAT_23ee28760 = *_DAT_23ee28760 + 1;
    goto LAB_23c62d9eb;
  }
  iVar9 = FUN_23a35ebd0(param_1,*(longlong *)(pcVar22 + 8),*(undefined8 *)PyExc_Exception_exref);
  if (iVar9 == 0) {
    pcVar22 = *(code **)(param_1 + 0x138);
    if ((pcVar22 == pcVar24) || (pcVar22 == (code *)0x0)) {
      plStack_d8 = *(longlong **)PyExc_RuntimeError_exref;
      pcStack_d0 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar22 = *(code **)(param_1 + 0x138);
      *plStack_d8 = *plStack_d8 + 1;
      *(code **)(param_1 + 0x138) = pcStack_e0;
      if ((pcVar22 == (code *)0x0) ||
         (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 != 0)) {
        iVar23 = 0xca;
        goto LAB_23c62e0b0;
      }
      iVar23 = 0xca;
      pcVar24 = (code *)0x0;
LAB_23c62dd46:
      (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
      iVar9 = iVar23;
      if (pcVar24 != (code *)0x0) goto LAB_23c62dd65;
      if (iVar23 != 0) goto LAB_23c62e0b0;
    }
    else {
      plStack_d8 = *(longlong **)(pcVar22 + 8);
      pcVar24 = *(code **)(pcVar22 + 0x28);
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
      *plStack_d8 = *plStack_d8 + 1;
      iVar23 = 0;
      pcStack_d0 = pcVar22;
      if (pcVar24 != (code *)0x0) {
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        if (plVar2 == *(longlong **)(pcVar24 + 0x18)) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar24 + 0x24);
        }
        *(code **)(param_1 + 0x138) = pcStack_e0;
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
        iVar9 = iVar23;
        if (*(longlong *)pcVar22 != 0) goto LAB_23c62dd65;
        goto LAB_23c62dd46;
      }
      *(code **)(param_1 + 0x138) = pcStack_e0;
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
      if (*(longlong *)pcVar22 == 0) goto LAB_23c62dd46;
    }
    iVar23 = (int)plVar2[5];
  }
  else {
    pplStack_c8 = *(longlong ***)(param_1 + 0x138);
    *pplStack_c8 = (longlong *)((longlong)*pplStack_c8 + 1);
    lVar12 = FUN_23ead5f40();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
      iVar23 = 0x102;
      plStack_d8 = plStack_78;
      pcStack_d0 = pcStack_70;
      pcVar24 = pcStack_68;
    }
    else {
      plVar16 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23ee284c0);
      plVar11 = _DAT_23ee28768;
      if (plVar16 == (longlong *)0x0) {
LAB_23c62f256:
        plStack_d8 = *(longlong **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x70);
        iVar23 = 0x102;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_d0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar12 = *(longlong *)(param_1 + 0x10);
        plVar13 = *(longlong **)(lVar12 + 0xe20);
        if (plVar13 == (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar14 = plVar13[3];
          *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
          *(longlong *)(lVar12 + 0xe20) = lVar14;
          *plVar13 = 1;
        }
        plVar13[4] = 0;
        lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
        lVar14 = plVar13[-1];
        puVar3 = *(undefined8 **)(lVar12 + 8);
        *puVar3 = plVar13 + -2;
        plVar13[-2] = lVar12;
        plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar12 + 8) = plVar13 + -2;
        plVar20 = DAT_23ed6a4c0;
        *plVar11 = *plVar11 + 1;
        plVar13[3] = (longlong)plVar11;
        pcVar24 = DAT_23ed6cd28;
        plVar11 = plVar10;
        plVar15 = plVar18;
        if (plVar20 == (longlong *)0x0) {
          plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar20 == (longlong *)0x0) goto LAB_23c62f670;
          *plVar20 = *plVar20 + 1;
          DAT_23ed6a4c0 = plVar20;
        }
        pcStack_a0 = pcVar24;
        pplStack_a8 = pplStack_c8;
        lVar12 = FUN_23e94ed00(param_1,plVar20,&pplStack_a8);
        if (lVar12 == 0) {
          plStack_d8 = *(longlong **)(param_1 + 0x60);
          pcVar24 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_d0 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          lVar12 = *plVar13;
          iVar23 = 0x102;
          *plVar13 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
            iVar23 = 0x102;
          }
        }
        else {
          plVar13[4] = lVar12;
          plVar20 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar20 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0x102;
            plVar13 = (longlong *)FUN_23e914090(param_1,plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
            if (plVar13 != (longlong *)0x0) {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              lVar12 = *(longlong *)(param_1 + 0x10);
              plVar16 = *(longlong **)(lVar12 + 0xe20);
              if (plVar16 == (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                lVar12 = *(longlong *)(param_1 + 0x10);
                plVar13 = *(longlong **)(lVar12 + 0xe20);
              }
              else {
                plVar13 = (longlong *)plVar16[3];
                *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                *(longlong **)(lVar12 + 0xe20) = plVar13;
                *plVar16 = 1;
              }
              plVar16[4] = 0;
              lVar14 = *(longlong *)
                        (*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
              lVar4 = plVar16[-1];
              puVar3 = *(undefined8 **)(lVar14 + 8);
              *puVar3 = plVar16 + -2;
              pcVar24 = _Py_FalseStruct_exref;
              plVar16[-2] = lVar14;
              plVar16[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar14 + 8) = plVar16 + -2;
              plVar20 = _DAT_23ee28770;
              *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
              plVar16[3] = (longlong)pcVar24;
              if (plVar13 == (longlong *)0x0) {
                plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar14 = plVar13[3];
                *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                *(longlong *)(lVar12 + 0xe20) = lVar14;
                *plVar13 = 1;
              }
              plVar13[4] = 0;
              lVar12 = *(longlong *)
                        (*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
              lVar14 = plVar13[-1];
              puVar3 = *(undefined8 **)(lVar12 + 8);
              *puVar3 = plVar13 + -2;
              plVar13[-2] = lVar12;
              plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar12 + 8) = plVar13 + -2;
              *plVar20 = *plVar20 + 1;
              plVar13[3] = (longlong)plVar20;
              pplVar21 = (longlong **)FUN_23e8bd350(pplStack_c8);
              pcVar24 = DAT_23ed6cd28;
              if (pplVar21 != (longlong **)0x0) {
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar20 == (longlong *)0x0) goto LAB_23c62f670;
                  *plVar20 = *plVar20 + 1;
                  DAT_23ed6a4c0 = plVar20;
                }
                pcStack_a0 = pcVar24;
                pplStack_a8 = pplVar21;
                lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pplStack_a8);
                *pplVar21 = (longlong *)((longlong)*pplVar21 + -1);
                if (*pplVar21 == (longlong *)0x0) {
                  (*(code *)pplVar21[1][6])(pplVar21);
                }
                if (lVar12 != 0) {
                  plVar13[4] = lVar12;
                  lVar12 = PyUnicode_Join(DAT_23ed6cd28,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (lVar12 == 0) goto LAB_23c62f683;
                  plVar16[4] = lVar12;
                  plVar2 = *pplStack_c8;
                  *pplStack_c8 = (longlong *)((longlong)plVar2 + -1);
                  if ((longlong *)((longlong)plVar2 + -1) == (longlong *)0x0) {
                    (*(code *)pplStack_c8[1][6])(pplStack_c8);
                  }
                  goto LAB_23c62d9eb;
                }
              }
              plStack_d8 = *(longlong **)(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_d0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              goto LAB_23c62f2c8;
            }
            goto LAB_23c62f256;
          }
          plStack_d8 = *(longlong **)(param_1 + 0x60);
          pcVar24 = *(code **)(param_1 + 0x70);
          iVar23 = 0x102;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_d0 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          lVar12 = *plVar16;
          *plVar16 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            FUN_23a334bc0(plVar16);
            iVar23 = 0x102;
          }
        }
      }
    }
LAB_23c62f150:
    plVar11 = *pplStack_c8;
    *pplStack_c8 = (longlong *)((longlong)plVar11 + -1);
    iVar9 = iVar23;
    if ((longlong *)((longlong)plVar11 + -1) == (longlong *)0x0) {
      (*(code *)pplStack_c8[1][6])(pplStack_c8);
      pcVar22 = *(code **)(param_1 + 0x138);
      *(code **)(param_1 + 0x138) = pcStack_e0;
      if (pcVar22 != (code *)0x0) goto LAB_23c62f18b;
      if (pcVar24 != (code *)0x0) {
        plVar11 = *(longlong **)(pcVar24 + 0x18);
        goto joined_r0x00023c62e1e9;
      }
    }
    else {
      pcVar22 = *(code **)(param_1 + 0x138);
      *(code **)(param_1 + 0x138) = pcStack_e0;
      if (pcVar22 == (code *)0x0) {
        if (pcVar24 == (code *)0x0) goto LAB_23c62e0b0;
        plVar11 = *(longlong **)(pcVar24 + 0x18);
        goto joined_r0x00023c62e1e9;
      }
LAB_23c62f18b:
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
      if (*(longlong *)pcVar22 == 0) goto LAB_23c62dd46;
      if (pcVar24 != (code *)0x0) goto LAB_23c62dd65;
    }
  }
LAB_23c62e0b0:
  pcVar22 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar24 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar24;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar22 + 0x10) = 0;
  *(longlong **)(pcVar22 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  *(int *)(pcVar22 + 0x24) = iVar23;
  lVar12 = *(longlong *)(pcStack_e8 + 0x1f8);
  *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
  lVar14 = *(longlong *)(pcVar22 + -8);
  plVar11 = *(longlong **)(lVar12 + 8);
  *plVar11 = (longlong)(pcVar22 + -0x10);
  *(longlong *)(pcVar22 + -0x10) = lVar12;
  *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar11;
  *(code **)(lVar12 + 8) = pcVar22 + -0x10;
LAB_23c62de20:
  FUN_23e8bba40(plVar2,"ooooooooo",plVar1,plVar19,plVar18,plVar10,plStack_108,plVar17,plStack_f8,
                plStack_100,0);
  if (_DAT_23ee29c90 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23ee29c90 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar12 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  plVar11 = (longlong *)plVar2[2];
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar12 = *plStack_100, *plStack_100 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  lVar12 = *plVar1;
  *plVar1 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_d8,pcStack_d0,pcVar22);
  return (longlong *)0x0;
}
